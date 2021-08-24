#!/usr/bin/env python

line = int(input())

for _ in range(line):
    question = input()

    stack = []
    for char1 in question:
        if len(stack) > 0:
            top = stack[-1]
        else:
            top = None

        if char1 == ')' and top == '(' :
            stack.pop()
        elif char1 == ']' and top == '[' :
            stack.pop()
        elif char1 == '}' and top == '{' :
            stack.pop()
        elif char1 == '>' and top == '<' :
            stack.pop()
        else:
            stack.append(char1)

    if len(stack) == 0:
        print('Y')
    else:
        print('N')
