#!/usr/bin/env python
import subprocess
import sys

filename = "./mini_patch"

def filling(seek, num, wf):
    wf.seek(seek)
    wf.write(b'a' * num)

def write_seek(read_file, new_file, seek_num):
    with open(read_file, "rb") as rf:
        with open(new_file, "wb") as wf:
            wf.write(rf.read())
            wf.seek(seek_num)
            wf.write(b'A')

for i in range(300):
    if i == 0:
        write_seek("./mini", "./mini_patch", i)
        subprocess.call(['cp',"./mini", "./mini_good"])
    else:
        write_seek("./mini_good", "./mini_patch", i)
    try:
        subprocess.call(['chmod','+x', filename])
        print(subprocess.check_output([filename]))
        print('good')
        subprocess.call(['mv',"./mini_patch", "./mini_good"])
    except:
        print('gg')
