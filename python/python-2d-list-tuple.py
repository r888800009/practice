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
    list_2d = []
    tuple_2d = tuple()
    for i in range(size):
        list_2d.append([j for j in range(size)])
        tuple_2d += (tuple([j for j in range(size)]),)

    """
    start = time.time()
    for i in range(size):
        for j in range(size):
            tuple_2d[i][j] = i * j
    end = time.time()
    print("random assign tuple", end - start)

    start = time.time()
    for i in range(size):
        for j in range(size):
            list_2d[i][j] = i * j
    end = time.time()
    print("random assign list", end - start)
    """

    start = time.time()
    for i in range(size):
        for j in range(size):
            a = tuple_2d[i][j] == 3
    end = time.time()
    print("random access tuple", end - start)

    start = time.time()
    for i in range(size):
        for j in range(size):
            a = list_2d[i][j] == 3
    end = time.time()
    print("random access list", end - start)

