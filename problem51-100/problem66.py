import math

def pell_equation(K):
    m = 0
    d = 1
    a0 = a = int(math.sqrt(K))

    xx = 1
    yy = 0

    x = a
    y = 1

    while x * x - K * y * y != 1:
        m = d * a - m
        d = (K - m * m) / d
        a = (a0 + m) / d

        xxx = xx
        xx = x
        yyy = yy
        yy = y

        x = a * xx + xxx
        y = a * yy + yyy

    return x

ans = 0
ansX = 0

for x in range(2, 1001):
    sqrtX = int(math.sqrt(x))
    if sqrtX * sqrtX == x:
        continue
    k = pell_equation(x)
    if k > ans:
        ans = k
        ansX = x

print(ansX)
print(ans)
