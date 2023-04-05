#!/usr/bin/env python
#!/usr/bin/env python
import os, sys
import functools
import time

print("""this file is evaluate python set vs fixed size list hashtable""")

access_time = 10000

for size in range(1000, 1000*10, 1000):
    print("size", size)

    print("init")
    list_table = [0] * size
    set_1 = set()
    for i in range(size):
        list_table[i] = i
        set_1.add(i)

    start = time.time()
    for i in range(size):
        for j in range(access_time):
            a = list_table[i] == 3
    end = time.time()
    print("access list", end - start)

    start = time.time()
    for i in range(size):
        for j in range(access_time):
            a = 3 in list_table
    end = time.time()
    print("access `n` in list", end - start)

    start = time.time()
    for i in range(size):
        for j in range(access_time):
            a = 3 in set_1

    end = time.time()
    print("access `n` in set", end - start)

