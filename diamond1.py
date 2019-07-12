#!/usr/bin/env python
def contain(x, y, size):
    center = size // 2;
    return (x >= center - y and x <= center + y) and y >= 0

def print_line(y, size, w):
    for x in range(0, size):
        condition = contain(x, y, size) and not contain(x, y - w, size)
        print("*" if condition else "_" , end = "")
    print()

def printAll(size, w):
    # Upper half
    for y in range(0, size // 2):
        print_line(y, size, w)
    # Lower half
    for y in range(size // 2, 0 - 1, -1):
        print_line(y, size, w)

printAll(21, 3)
printAll(13, 4)
printAll(13, 3)
printAll(7, 2)
printAll(31, 1)
