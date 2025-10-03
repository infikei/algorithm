# Solve 2025-10-03

import sys

input = lambda: sys.stdin.readline().rstrip()

def recur(a, b, l, k, p, q):
    if l == 0:
        return 1

    r = 3 ** (k - 1) * 1000
    r2 = r * 2
    r3 = r * 3

    if p > a + r and p < a + r2 and q > b + r and q < b + r2:
        return 0

    na = a + r2 if p >= a + r2 else a + r if p >= a + r else a
    nb = b + r2 if q >= b + r2 else b + r if q >= b + r else b
    return recur(na, nb, l - 1, k - 1, p, q)


for _ in range(int(input())):
    a, b, l, k, p, q = input().split()
    a, b, l, k = map(int, (a, b, l, k))

    a *= 1000
    b *= 1000
    p_sign = -1 if p[0] == "-" else 1
    q_sign = -1 if q[0] == "-" else 1
    p = int(p[:-4]) * 1000 + p_sign * int(p[-3:])
    q = int(q[:-4]) * 1000 + q_sign * int(q[-3:])

    if p < a or p > a + 3 ** k * 1000 or q < b or q > b + 3 ** k * 1000:
        print(0)
        continue

    print(recur(a, b, l, k, p, q))
