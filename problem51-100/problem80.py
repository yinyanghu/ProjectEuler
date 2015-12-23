import decimal

N = 100
decimal.getcontext().prec = 105

Y = pow(10, N - 1)

ans = 0

for X in range(2, N):
    sqrtX = decimal.Decimal(X).sqrt()
    if sqrtX % 1 != 0:
        ans += sum(int(c) for c in str(sqrtX * Y)[:N])

print(ans)
