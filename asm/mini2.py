#!/usr/bin/env python
import subprocess
import sys
from pwn import *

filename = "./mini"

#entry = 0x38+2
hello_off = 0x28
hello_str = 'Hello world!\n'

code1_off = 0x4
code2_off = 0x58
code3_off = 0x38+2

exit_off = 0x70
entry = code1_off

"""
writable is marked A
00000000: 7f45 4c46 4141 4141 4141 4141 4141 4141  .ELFAAAAAAAAAAAA
00000010: 0200 3e00 4141 4141 7000 0100 0000 0000  ..>.AAAAp.......
00000020: 4000 0000 0000 0000 4141 4141 4141 4141  @.......AAAAAAAA
00000030: 4141 4141 4141 3800 0100 4141 4141 4141  AAAAAA8...AAAAAA
00000040: 0100 0000 4141 4141 0000 0000 0000 0000  ....AAAA........
00000050: 0000 0100 0000 0000 4141 4141 4141 4141  ........AAAAAAAA
00000060: b000 0000 0000 0000 b000 0000 0000 0000  ................
00000070: 31ff 6a3c 580f 0541 4141 4141 4141 4141  1.j<X..AAAAAAAAA
000000a0: 4141 4141 4141 4141 4141 4141 4141 4141  AAAAAAAAAAAAAAAA

as mini.s -o mini.o
ld -T mini.ld -s -o ./mini mini.o
python3 ./mini2.py
wc mini2
./mini2
"""

context.os='linux'
context.arch = 'amd64'

with open("./mini", "rb") as rf:
    with open("./mini2", "wb") as wf:
        # only read 0x78
        wf.write(rf.read(0x78))

        # entry overwrite
        wf.seek(0x18)
        wf.write(bytes([entry]))

        # set Number of program headers
        wf.seek(0x38)
        wf.write(bytes([1]))

        # mark R-X
        wf.seek(0x44)
        wf.write(bytes([5]))

        # write hello
        wf.seek(hello_off)
        wf.write(b'Hello world!\n')
        print(len(hello_str))

        # write code 1
        code1 = """
            /* 3 bytes */
            push {}
            pop rdx

            /* 5 bytes */
            push {}
        """.format(hex(len(hello_str)), hex(0x10000 + hello_off))
        wf.seek(code1_off)
        wf.write(asm(code1) + b'\xeb\x4a') # hex(0x58-0x0c-2)

        # write code 2
        code2 = """
            /* 1 + 3 + 2 bytes */
            pop rsi
            push 1
            pop rdi
            push SYS_write
        """
        wf.seek(code2_off)
        wf.write(asm(code2) + b'\xeb\xda') # hex(0x3a-0x60)

        # write code 3
        code3 = """
            /* 4 bytes */
            pop rax
            nop
            syscall
        """
        wf.seek(code3_off)
        wf.write(asm(code3) + b'\xeb\x30') # hex(0x70-0x50-14)


        # we write to LMA most equal VMA
        """
        data = asm('nop;nop;nop;nop;nop;')
        data = b'AAAAA'
        wf.seek(0x60)
        wf.write(bytes(data))
        wf.seek(0x68)
        wf.write(bytes(data))
        """

        # write exit()
        wf.seek(exit_off)
        wf.write(asm(shellcraft.exit(0)))

subprocess.call(['chmod','+x', "./mini2"])
print(subprocess.check_output(["./mini2"]))
