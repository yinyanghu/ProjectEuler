import itertools
import math

N = 10 ** 25

base2 = []

F = {}

def dfs(k, x):
    global F
    if x == 0:
        return 1
    if k == len(base2):
        return 0

    if x > base2[k] * 4 - 2:
        return 0

    total = 0

    if x >= base2[k]:
        if not (k + 1, x - base2[k]) in F:
            F[(k + 1, x - base2[k])] = dfs(k + 1, x - base2[k])
        total += F[(k + 1, x - base2[k])]

    if x >= 2 * base2[k]:
        if not (k + 1, x - base2[k] * 2) in F:
            F[(k + 1, x - base2[k] * 2)] = dfs(k + 1, x - base2[k] * 2)
        total += F[(k + 1, x - base2[k] * 2)]

    if not (k + 1, x) in F:
        F[(k + 1, x)] = dfs(k + 1, x)
    total += F[(k + 1, x)]
    return total

def solve():
    x = 1
    while x <= N:
        base2.append(x)
        x = x * 2
    base2.reverse()
    ans = dfs(0, N)
    print(ans)

solve()
