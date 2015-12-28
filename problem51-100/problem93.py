import itertools
import operator
from sets import Set

candidate = list(itertools.combinations(range(0, 10), 4))

ops = [operator.add, operator.sub, operator.mul, operator.truediv]

def expression(S):
    Pi = list(itertools.permutations(S))
    Ops = list(itertools.product(ops, repeat=3))
    key = Set()
    for pi in Pi:
        for op in Ops:
            try:
                k1 = op[0](op[1](op[2](pi[0], pi[1]), pi[2]), pi[3])
            except ZeroDivisionError:
                pass
            else:
                if k1 % 1 == 0 and k1 > 0:
                    key.add(k1)

            try:
                k2 = op[0](op[1](pi[0], pi[1]), op[2](pi[2], pi[3]))
            except ZeroDivisionError:
                pass
            else:
                if k2 % 1 == 0 and k2 > 0:
                    key.add(k2)

            #print(pi, op, k1, k2)
            #key.add(k1)
            #key.add(k2)
    for x in itertools.count(1):
        if not x in key:
            return x - 1

#print(expression((1, 2, 3, 4)))
#print("------------------------------")
#print(expression((1, 2, 5, 8)))

ans = 0
for s in candidate:
    k = expression(s)
    if k > ans:
        ans = k
        print(s, k)


