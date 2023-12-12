# Solve 2023-12-12

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    n = int(input())

    if n == 0:
        break

    a, b, c = map(int, input().split())

    if b * 2 == a + c:
        d = b - a
        print(n * (2 * a + (n - 1) * d) // 2)
    else:
        r = b // a
        print(a * (r ** n - 1) // (r - 1))
