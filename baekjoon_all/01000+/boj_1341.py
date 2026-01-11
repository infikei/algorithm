# Solve 2026-01-11

import sys

input = lambda: sys.stdin.readline().rstrip()

def get_gcd(a, b):
    while b > 0:
        a, b = b, a % b

    return a


def reduce_frac(a, b):
    g = get_gcd(a, b)

    if g == 0:
        return a, b

    return a // g, b // g


def sub_frac(a, b, c, d):
    return a * d - b * c, b * d


a, b = map(int, input().split())
p, q = a, b
ans = ""

for i in range(1, 61):
    na, nb = sub_frac(a, b, 1, pow(2, i))

    if na >= 0:
        ans += "*"
        a, b = reduce_frac(na, nb)
    else:
        ans += "-"

    p, q = reduce_frac(p, q * 2)

    if a == p and b == q:
        break
else:
    ans = -1

print(ans)
