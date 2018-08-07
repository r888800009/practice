#!/usr/bin/env python

w = 60
h = 30

include_w = 20
include_h = 10

pos_x = -10
pos_y = 10

for y in range(0, h):
    for x in range(0, w):
        if abs((x - pos_x) - w / 2 ) <= include_w / 2 * ((y - pos_y) / include_h) and (y - pos_y) <= include_h:
            print(" ", end="")
        else:
            print("*", end="")
    print()
