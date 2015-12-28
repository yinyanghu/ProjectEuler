import math

GOAL = 1000000

def solve():
    total = 0
    x = 0
    while True:
        x += 1
        X = x * x
        for y in range(2, 2 * x + 1):
            k = X + y * y
            sqrtK = int(math.sqrt(k))
            if sqrtK * sqrtK == k:
                if y <= x:
                    total += y / 2
                else:
                    total += x - (y + 1) / 2 + 1
        print(x, total)
        if total > GOAL:
            print(x)
            break

solve()