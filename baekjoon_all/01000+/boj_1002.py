# Solve 2023-03-13

import sys
from math import sqrt

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    ans = 0

    if x1 == x2 and y1 == y2 and r1 == r2:
        ans = -1
    else:
        dx = x1 - x2
        dy = y1 - y2
        d = sqrt(dx ** 2 + dy ** 2)

        min_d = abs(r1 - r2)
        max_d = r1 + r2
        
        if d < min_d or d > max_d:
            ans = 0
        elif d == min_d or d == max_d:
            ans = 1
        else:
            ans = 2

    print(ans)
