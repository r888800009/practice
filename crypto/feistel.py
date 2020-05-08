#!/usr/bin/env python
import random

def gen_subkeys(round_time, key):
    subkey = random.Random(key)
    result = []
    while round_time > 0:
        result.append(subkey.random())
        round_time -= 1
    return result

def round_func(str1, subkey):
    rand = random.Random(subkey)
    result = ''
    for i in str1:
        result += chr((ord(i) + rand.randint(0, 0xff)) % 0xff)

    return result

def string_xor(str1, str2):
    if len(str1) != len(str2):
        raise ValueError("length error")

    result = ''
    for i in range(0, len(str1)):
        result += chr(ord(str1[i]) ^ ord(str2[i]))

    return result

def encrypt(plaintext, round_time, key):
    if len(plaintext) % 2 != 0:
        raise ValueError("text must even")

    end = len(plaintext)
    p = end // 2

    LE = plaintext[0:p]
    RE = plaintext[p:end]

    subkeys_list = gen_subkeys(round_time, key)

    for subkey in subkeys_list:
        func_out = round_func(RE, subkey)
        LE, RE = RE, string_xor(func_out, LE)

    return RE + LE

def decrypt(ciphertext, round_time, key):
    if len(ciphertext) % 2 != 0:
        raise ValueError("text  must even")

    end = len(ciphertext)
    p = end // 2

    LD = ciphertext[0:p]
    RD = ciphertext[p:end]

    subkeys_list = gen_subkeys(round_time, key)
    subkeys_list.reverse()

    for subkey in subkeys_list:
        func_out = round_func(RD, subkey)
        LD, RD = RD, string_xor(func_out, LD)

    return RD + LD

print(decrypt(encrypt('plaintext1', 10000, 'key'), 10000, 'key'))
# print(encrypt('plaintext1', 100, 'key'))
