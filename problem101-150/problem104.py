from math import sqrt, log

MOD = 10 ** 9
digit_std = list(range(1, 10))

def get_digits(x):
    lst = []
    while x > 0:
        lst.append(x % 10)
        x = x / 10
    return lst

phi = (1 + sqrt(5)) / 2

def fibonacci():
    N = 2
    a, b = 1, 1
    while True:
        N += 1
        #print(N)
        c = (a + b) % MOD
        a, b = b, c

        last = get_digits(c)
        last.sort()
        if last != digit_std:
            continue

        logF = N * log(phi, 10) - log(sqrt(5), 10)
        C = int(pow(10, logF - int(logF - 8)))
        first = get_digits(C)
        first.sort()
        if first != digit_std:
            continue
        print(N)
        break

fibonacci()
#print(get_digits(1234545))