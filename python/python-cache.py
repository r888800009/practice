#!/usr/bin/env python
import os, sys
import functools
import time

print("""this file is evaluate python cache speed""")
      

cache = {}
def dict_cache(n):
    if n in cache:
        return cache[n]
    else:
        time.sleep(0.001)
        cache[n] = n
        return n
    
@functools.cache
def functools_cache(n):
    time.sleep(0.001)
    return n

print("first time")
start = time.time()
for i in range(1000):
    dict_cache(i)
end = time.time()
print("dict_cache: ", end - start)

start = time.time()
for i in range(1000):
    functools_cache(i)
end = time.time()
print("functools_cache: ", end - start)

print("second time for evaluate cache speed")
start = time.time()
for j in range(100000):
    for i in range(1000):
        dict_cache(i)
end = time.time()
print("dict_cache: ", end - start)

start = time.time()
for j in range(100000):
    for i in range(1000):
        functools_cache(i)
end = time.time()
print("functools_cache: ", end - start)

