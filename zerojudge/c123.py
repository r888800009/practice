#!/usr/bin/env python

line = input()
while line != '0':
    length = int(line)

    line = input()
    while line != '0':
        stack = []

        rail = line.split()
        if len(rail) == length:
            next_way = length
            for i in range(len(rail) - 1, -1, -1)  :
                rail[i] = int(rail[i])
                #print(stack, next_way)
                while stack and stack[-1] == next_way:
                    # not empry
                    pop = stack.pop()
                    #print('pop', pop)
                    next_way -= 1

                if rail[i] == next_way:
                    next_way -= 1
                else:
                    # push 
                    #print('push', rail[i])
                    stack.append(rail[i])

                while stack and stack[-1] == next_way:
                    # not empry
                    pop = stack.pop()
                    #print('pop', pop)
                    next_way -= 1
            
            if next_way != 0 or len(stack) != 0:
                print('No')
            else:
                print('Yes')
        else:
            print('No')

        line = input()

    line = input()
    print()
