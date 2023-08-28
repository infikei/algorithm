# Solve 2023-08-28

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(3):
    h1, m1, s1, h2, m2, s2 = map(int, input().split())

    h2 -= h1
    m2 -= m1
    s2 -= s1

    while s2 < 0:
        s2 += 60
        m2 -= 1

    while m2 < 0:
        m2 += 60
        h2 -= 1

    print(h2, m2, s2, sep=" ")
