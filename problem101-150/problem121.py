from copy import deepcopy
p = [1, 1]

T = 15

for t in range(2, T + 1):
    last = deepcopy(p)
    p.append(0)
    for i in range(len(last)):
        p[i + 1] += last[i] * t

print(p)
total = sum(p)
win = sum(p[:len(p) / 2])
ans = total / win
print(ans)
