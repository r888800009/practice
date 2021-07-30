#!/usr/bin/env python3

from __future__ import print_function
from triton     import *

import string
import sys
import os
import lief

"""
Apache-2.0 License
References
- https://github.com/JonathanSalwan/Triton/tree/master/src/examples/python
- https://ch3nye.top/%E6%B1%A1%E7%82%B9%E5%88%86%E6%9E%90%E6%8A%80%E6%9C%AF%E7%AC%94%E8%AE%B0/
- https://triton.quarkslab.com/documentation/doxygen/classtriton_1_1engines_1_1taint_1_1TaintEngine.html
- https://github.com/JonathanSalwan/Triton/blob/master/src/testers/unittests/test_taint.py
- https://github.com/JonathanSalwan/Triton/blob/master/src/examples/python/forward_tainting.py
- https://github.com/JonathanSalwan/Triton/blob/master/src/examples/python/small_x86-64_symbolic_emulator.py
"""

DEBUG = True
DEBUG_PC = False

# Memory mapping
BASE_PLT   = 0x10000000
BASE_ARGV  = 0x20000000
BASE_STACK = 0x9fffffff


def __libc_start_main(ctx):
    debug('__libc_start_main hooked')

    # Get arguments
    main = ctx.getConcreteRegisterValue(ctx.registers.rdi)

    # Push the return value to jump into the main() function
    ctx.setConcreteRegisterValue(ctx.registers.rsp, ctx.getConcreteRegisterValue(ctx.registers.rsp)-CPUSIZE.QWORD)

    ret2main = MemoryAccess(ctx.getConcreteRegisterValue(ctx.registers.rsp), CPUSIZE.QWORD)
    ctx.setConcreteMemoryValue(ret2main, main)

    # Setup argc / argv
    ctx.concretizeRegister(ctx.registers.rdi)
    ctx.concretizeRegister(ctx.registers.rsi)

    # Setup target argvs
    argvs = []

    # Define argc / argv
    base  = BASE_ARGV
    addrs = list()

    index = 0
    for argv in argvs:
        addrs.append(base)
        ctx.setConcreteMemoryAreaValue(base, bytes(argv.encode('utf8')) + b'\x00')

        # Tainting argvs
        for i in range(len(argv)):
            ctx.taintMemory(base + i)

        base += len(argv)+1
        debug('argv[%d] = %s' %(index, argv))
        index += 1

    argc = len(argvs)
    argv = base
    for addr in addrs:
        ctx.setConcreteMemoryValue(MemoryAccess(base, CPUSIZE.QWORD), addr)
        base += CPUSIZE.QWORD

    ctx.setConcreteRegisterValue(ctx.registers.rdi, argc)
    ctx.setConcreteRegisterValue(ctx.registers.rsi, argv)

    return 0

def getMemoryString(ctx, addr):
    s = str()
    index = 0

    while ctx.getConcreteMemoryValue(addr+index):
        c = chr(ctx.getConcreteMemoryValue(addr+index))
        if c not in string.printable: c = ""
        s += c
        index  += 1

    return s


def __strncpy(ctx):
    debug('__strncpy hooked')

    # Get arguments
    # rdi rsi rdx
    dist = ctx.getConcreteRegisterValue(ctx.registers.rdi)
    src_addr = ctx.getConcreteRegisterValue(ctx.registers.rsi)
    src = getMemoryString(ctx, src_addr)
    num = ctx.getConcreteRegisterValue(ctx.registers.rdx)
    print('src', hex(ctx.getConcreteRegisterValue(ctx.registers.rsi)), src)
    for i in range(min(len(src), num)):
        if ctx.isMemoryTainted(src_addr + i):
            ctx.taintMemory(dist + i)
        ctx.setConcreteMemoryValue(dist + i, ord(src[i]))

    # Return value
    return ctx.getConcreteRegisterValue(ctx.registers.rdi)

def __puts(ctx):
    debug('puts hooked')

    # Get arguments
    arg1 = getMemoryString(ctx, ctx.getConcreteRegisterValue(ctx.registers.rdi))
    sys.stdout.write(arg1 + '\n')

    # Return value
    return len(arg1) + 1

"""
if call not working
make sure you set hooking PLT
"""
customRelocation = [
    ['__libc_start_main', __libc_start_main,    BASE_PLT + 0],
    ['puts',              __puts,               BASE_PLT + 1],
    ['strncpy',           __strncpy,            BASE_PLT + 2],
]


def debug_pc(pc):
    if DEBUG_PC: print(hex(pc))

def debug(s):
    if DEBUG: print(s)

def loadBinary(ctx, binary):
    # Map the binary into the memory
    phdrs = binary.segments
    for phdr in phdrs:
        size   = phdr.physical_size
        vaddr  = phdr.virtual_address
        debug('[+] Loading 0x%06x - 0x%06x' %(vaddr, vaddr+size))
        ctx.setConcreteMemoryAreaValue(vaddr, phdr.content)
    return

def makeRelocation(ctx, binary):
    # Perform our own relocations
    try:
        for rel in binary.pltgot_relocations:
            symbolName = rel.symbol.name
            symbolRelo = rel.address
            for crel in customRelocation:
                if symbolName == crel[0]:
                    debug('[+] Hooking %s' %(symbolName))
                    ctx.setConcreteMemoryValue(MemoryAccess(symbolRelo, CPUSIZE.QWORD), crel[2])
    except:
        pass

    # Perform our own relocations
    try:
        for rel in binary.dynamic_relocations:
            symbolName = rel.symbol.name
            symbolRelo = rel.address
            for crel in customRelocation:
                if symbolName == crel[0]:
                    debug('[+] Hooking %s' %(symbolName))
                    ctx.setConcreteMemoryValue(MemoryAccess(symbolRelo, CPUSIZE.QWORD), crel[2])
    except:
        pass
    return

def hookingHandler(ctx):
    pc = ctx.getConcreteRegisterValue(ctx.registers.rip)
    for rel in customRelocation:
        if rel[2] == pc:
            # Emulate the routine and the return value
            ret_value = rel[1](ctx)
            if ret_value is not None:
                ctx.setConcreteRegisterValue(ctx.registers.rax, ret_value)

            # Get the return address
            ret_addr = ctx.getConcreteMemoryValue(MemoryAccess(ctx.getConcreteRegisterValue(ctx.registers.rsp), CPUSIZE.QWORD))

            # Hijack RIP to skip the call
            ctx.setConcreteRegisterValue(ctx.registers.rip, ret_addr)

            # Restore RSP (simulate the ret)
            ctx.setConcreteRegisterValue(ctx.registers.rsp, ctx.getConcreteRegisterValue(ctx.registers.rsp)+CPUSIZE.QWORD)
    return

def emulate(ctx, pc):
    global SERIAL
    global VALID


    # objdump -t ./a.out
    sink = 0x404070
    source = 0x404050

    # taint
    for i in range(10):
        # also see
        # https://github.com/JonathanSalwan/Triton/blob/master/src/testers/unittests/test_taint.py

        ctx.taintMemory(source + i)
        ctx.setConcreteMemoryValue(source + i, ord('a'))

    # run code
    count = 0
    while pc:
        opcodes = ctx.getConcreteMemoryAreaValue(pc, 16)

        debug_pc(pc)
        inst = Instruction(pc, opcodes)
        if ctx.processing(inst) == False:
            debug('[-] Instruction not supported: %s' %(str(inst)))
            break

        hookingHandler(ctx)



        # Next instruction
        pc = ctx.getConcreteRegisterValue(ctx.registers.rip)
        count += 1

    # tainted
    for i in range(10):
        if ctx.isMemoryTainted(sink + i):
            print('[tainted] %s' %(str(sink + i)))

    debug('[+] Instruction executed: %d' %(count))
    return

def run(ctx, binary):
    # Define a fake stack
    ctx.setConcreteRegisterValue(ctx.registers.rbp, BASE_STACK)
    ctx.setConcreteRegisterValue(ctx.registers.rsp, BASE_STACK)

    # Let's emulate the binary from the entry point
    debug('[+] Starting emulation.')
    emulate(ctx, binary.entrypoint)
    debug('[+] Emulation done.')
    return


if __name__ == '__main__':
    ctx = TritonContext()
    ctx.setArchitecture(ARCH.X86_64)

    # Symbolic optimization
    ctx.setMode(MODE.ALIGNED_MEMORY, True)

    # AST representation as Python syntax
    ctx.setAstRepresentationMode(AST_REPRESENTATION.PYTHON)

    # Parse and load the binary
    target = os.path.join(os.path.dirname(__file__), './a.out')
    binary = lief.parse(target)

    loadBinary(ctx, binary)

    # Perform our own relocations
    makeRelocation(ctx, binary)

    run(ctx, binary)


