from math import factorial

def choose(n, k):
    return factorial(n) / factorial(k) / factorial(n - k)

def catalan(n):
    return choose(2 * n, n) / (n + 1)

def F(n, k):
    return choose(n, k) * choose(n - k, k) / 2 - catalan(k) * choose(n, 2 * k)


N = 12
ans = 0
for k in range(2, N / 2 + 1):
    ans += F(N, k)
print(ans)