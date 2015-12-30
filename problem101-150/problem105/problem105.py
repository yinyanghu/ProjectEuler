from itertools import combinations

f = open('sets.txt', 'r')

def checkA(lst):
    H = {}
    for k in range(len(lst)):
        for c in combinations(lst, k):
            total = sum(c)
            if total in H:
                C = set(c)
                for s in H[total]:
                    if len(s & C) == 0:
                        return False
                H[total].append(C)
            else:
                H[total] = [set(c)]
    return True

def checkB(lst):
    L = lst[0]
    R = 0
    n = len(lst)
    for i in range(1, n):
        L += lst[i]
        R += lst[n - i]
        if L <= R:
            return False
    return True

ans = 0
c = 0
for line in f:
    c += 1
    print(c)
    lst = [int(x) for x in line.split(',')]
    lst.sort()
    if checkB(lst) and checkA(lst):
        ans += sum(lst)
print(ans)


