import itertools
from collections import namedtuple
from math import sqrt

Point = namedtuple("Point", "x y")
Vector = Point

def dot_product(v1, v2):
    return v1.x * v2.x + v1.y * v2.y

def normalize(v):
    l = sqrt(dot_product(v, v))
    return Vector(v.x / l, v.y / l)


def next((p, v)):
    t = normalize(Vector(-p.y, 4 * p.x))
    k = -2 * dot_product(v, t)
    vv = Vector(v.x + k * t.x, v.y + k * t.y)
    l = -2 * (4 * p.x * vv.x + p.y * vv.y) / (4 * vv.x ** 2 + vv.y ** 2)
    pp = Point(p.x + l * vv.x, p.y + l * vv.y)
    return (pp, vv)

def is_escaped(p):
    return p.y > 0 and -0.01 <= p.x <= 0.01

p = Point(1.4, -9.6)
v = normalize(Vector(1.4 - 0.0, -9.6 - 10.1))

ans = 0
while not is_escaped(p):
    ans += 1
    (p, v) = next((p, v))
print(ans)

