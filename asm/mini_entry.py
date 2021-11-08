#!/usr/bin/env python
import subprocess
import sys

filename = "./mini"

def filling(seek, num, wf):
    wf.seek(seek)
    wf.write(b'a' * num)

with open("./mini", "rb") as rf:
    with open("./mini_entry", "wb") as wf:
        wf.write(rf.read(0xb0))
        wf.seek(0x18)
        wf.write(b'\0')

subprocess.call(['chmod','+x', "./mini_entry"])
print(subprocess.check_output(["./mini_entry"]))
