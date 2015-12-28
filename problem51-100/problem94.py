import math

limit = 1000000000

# x^2 - 3 y^2 = 1
def pell_equation():
    x = x0 = 2
    y = y0 = 1

    yield (x, y)

    while True:
        xx = 2 * x + 3 * y
        yy = 2 * y + x

        x = xx
        y = yy

        yield (x, y)



def solve():
    ans = 0
    for (x, y) in pell_equation():
        a3 = 2 * x - 1
        area3 = y * (x - 2)
        if a3 > limit:
            break
        if a3 > 0 and area3 > 0 and a3 % 3 == 0 and area3 % 3 == 0:
            a = a3 / 3
            area = area3 / 3
            ans += 3 * a + 1

        a3 = 2 * x + 1
        area3 = y * (x + 2)
        if a3 > 0 and area3 > 0 and a3 % 3 == 0 and area3 % 3 == 0:
            a = a3 / 3
            area = area3 / 3
            ans += 3 * a - 1

    print(ans)

solve()
