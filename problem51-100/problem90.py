import itertools

Square = [(0, 1), (0, 4), (0, 9), (1, 6), (2, 5), (3, 6), (4, 9), (6, 4), (8, 1)]

candidate = list(itertools.combinations(range(0, 10), 6))

ans = 0
for x in candidate:
    X = list(x)
    if 6 in X:
        X.append(9)
    if 9 in X:
        X.append(6)

    for y in candidate:
        Y = list(y)
        if 6 in Y:
            Y.append(9)
        if 9 in Y:
            Y.append(6)

        total = 0
        for (l, r) in Square:
            if ((l in X) and (r in Y)) or ((l in Y) and (r in X)):
                total += 1
        if total == len(Square):
            ans += 1
print(ans / 2)
