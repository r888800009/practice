#!/usr/bin/env python

def merge(out, in1, in2):
    while in1 and in2:
        if in1[0] <= in2[0]:
            out.append(in1.pop(0))
        else:
            out.append(in2.pop(0))
    while in1:
        out.append(in1.pop(0))
    while in2:
        out.append(in2.pop(0))


a = [[i] for i in range(100, 0, -1)]

print(a)
while len(a) >= 2:
    in1 = a.pop(0)
    in2 = a.pop(0)
    out = []
    merge(out, in1, in2)
    a.append(out)

print(a)

