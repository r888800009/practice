#!/usr/bin/env python
#!/usr/bin/env python
import os, sys
import functools
import time

print("""this file is evaluate python set vs fixed size list hashtable""")

access_time = 10000 **2

for size in range(1000, 1000*10, 1000):
    print("size", size)

    print("init")
    list_1d = [j for j in range(size)]
    tuple_1d = tuple([j for j in range(size)])

    start = time.time()
    for i in range(size):
        a = tuple_1d[i] == 3
    end = time.time()
    print("random access tuple", end - start)

    start = time.time()
    for i in range(size):
        a = list_1d[i] == 3
    end = time.time()
    print("random access list", end - start)

    start = time.time()
    for item in tuple_1d:
        a = item == 3
    end = time.time()
    print("traversing tuple `in`", end - start)

    start = time.time()
    for item in list_1d:
        a = item == 3
    end = time.time()
    print("traversing list `in`", end - start)



