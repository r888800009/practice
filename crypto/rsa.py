import gmpy2
from gmpy2 import mpz
from Crypto.Util.number import long_to_bytes
from Crypto.Util.number import bytes_to_long
from binascii import hexlify

p = 3231660450893985129787028139151018035610437467522069485447060736495328441321407792079915113733222842630322770984020297415912649518117481856420586639729 
q = 7
n = gmpy2.mul(p, q)
e = 5
phi = gmpy2.mul(p-1, q-1)
d = gmpy2.invert(e, phi)

m = bytes_to_long(b'hello world')
print(m)
c = gmpy2.powmod(m, e, n)
m_rec = gmpy2.powmod(c, d, n)

print('n: ' + str(n))
print('d: ' + str(d))
print('c: ' + str(c))

gmpy2.iroot(c,5)
print(long_to_bytes(m_rec))
