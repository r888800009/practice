#!/usr/bin/env python

w = 60
h = 30

r = 5

pos_x = w / 2 + 5
pos_y = h / 2 + 4

for y in range(0, h):
    for x in range(0, w):
        if ((x - pos_x) / 2) ** 2 + (y - pos_y) ** 2 <= r ** 2:
            print(" ", end="")
        else:
            print("*", end="")
    print()
