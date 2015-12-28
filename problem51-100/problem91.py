import math

M = 50
allPoints = [(x, y) for x in range(0, M + 1) for y in range(0, M + 1)]

def is_right_triangle(A, B, C):
    if A == B or B == C or A == C:
        return False
    if (B[1] - A[1]) * (C[0] - A[0]) == (B[0] - A[0]) * (C[1] - A[1]):
        return False
    ab = (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1])
    bc = (B[0] - C[0]) * (B[0] - C[0]) + (B[1] - C[1]) * (B[1] - C[1])
    ac = (A[0] - C[0]) * (A[0] - C[0]) + (A[1] - C[1]) * (A[1] - C[1])
    lst = sorted([ab, bc, ac])
    return lst[0] + lst[1] == lst[2]

ans = 0
for x in allPoints:
    for y in allPoints:
        if is_right_triangle((0, 0), x, y):
            ans += 1
print(ans / 2)