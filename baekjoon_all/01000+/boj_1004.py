# Solve 2023-03-14

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for ti in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    ans = 0

    for ni in range(n):
        cx, cy, r = map(int, input().split())

        start = finish = False
        dx = x1 - cx
        dy = y1 - cy
        if dx ** 2 + dy ** 2 < r ** 2:
            start = True
        dx = x2 - cx
        dy = y2 - cy
        if dx ** 2 + dy ** 2 < r ** 2:
            finish = True

        if start != finish:
            ans += 1

    print(ans)
