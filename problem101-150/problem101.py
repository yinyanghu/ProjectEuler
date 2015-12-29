from numpy.polynomial import Polynomial as P

def LagrangeInterpolating(points):
    #n = len(points)
    X = [x for (x, y) in points]
    poly = P([0])
    for (x, y) in points:
        p = P([y])
        for xx in X:
            if xx != x:
                p = p * P([-xx, 1])
                p = p / P([x - xx])
        poly = poly + p
    return poly

N = 11
F = P([1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1])
Points = [(x, F(x)) for x in range(1, N + 1)]
print(Points)

ans = 0
for k in range(N - 1):
    poly = LagrangeInterpolating(Points[:k + 1])
    print(poly(k + 2))
    ans += poly(k + 2)
print(ans)



