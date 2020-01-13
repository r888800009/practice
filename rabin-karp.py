#!/usr/bin/env python
import sympy
prime = sympy.nextprime(5000)

def rabinKarp(findWord, text):
    findHash = 0
    for c in findword:
        findHash = (findHash + ord(c)) % prime

    print('finding \"{}\"'.format(findWord))
    print('hash is {}'.format(findHash))

    queueStart = 0
    queueEnd = len(findWord)
    lineno = 1

    # first sub string hash
    subStringHash = 0
    for c in text[queueStart:queueEnd]:
        subStringHash = (subStringHash + ord(c)) % prime

    # check match
    if subStringHash == findHash and text[queueStart:queueEnd] == findWord:
        print('at line {} found \"{}\"'.format(lineno, text[queueStart:queueEnd]))
        return

    while queueEnd < len(text):
        subStringHash = (subStringHash - ord(text[queueStart])) % prime
        subStringHash = (subStringHash + ord(text[queueEnd])) % prime
        queueStart += 1
        queueEnd += 1

        if text[queueStart] == '\n': lineno += 1

        # check match
        if subStringHash == findHash and text[queueStart:queueEnd] == findWord:
            print('at line {} found \"{}\"'.format(lineno, text[queueStart:queueEnd]))
            return

    print('not find')



with open('./rabin-karp.py') as file:
    findword = input('input a word: ')
    text = file.read()

    print('==== text content ====')
    print(text)
    print('====      END     ====')
    print()
    rabinKarp(findword, text)
