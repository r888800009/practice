#!/usr/bin/env python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
head = Node(-1)
cur = head

for i in range(10):
    cur.next = Node(i)
    cur = cur.next

cur = head
# print list
while cur != None:
    print(str(cur.value) + " ", end="")
    cur = cur.next
print()
