#!/usr/bin/python

def move(n, source, destination, tmp):
    if (n < 1):
        return
    move(n - 1, source, tmp, destination)
    print('move {0} fron {1} to {2}'.format( n,  source, destination))
    move(n - 1, tmp, destination, source)

move(3, "A", "C" , "B")
        

