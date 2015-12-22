from fractions import Fraction
from itertools import count 

def is_prime(x):
    for p in count(2):
        if p * p > x:
            return True
        if x % p == 0:
            return False

def gen_prime():
    for x in count(2):
        if is_prime(x):
            yield x

tau = Fraction(15499, 94744)
f = Fraction(1)

n = d = 1
for p in gen_prime():
    n *= p - 1
    d *= p
    if Fraction(n, d) < tau:
        break

for k in count(1):
    if Fraction(n * k, d * k - 1) < tau:
        break

ans = d * k
print(ans)