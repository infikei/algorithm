# Solve 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    ans = 0
    for a in range(1, n):
        tmp = a * a + m
        for b in range(a + 1, n):
            if (b * b + tmp) % (a * b) == 0:
                ans += 1

    print(ans)
