# Solve 2023-12-30

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    ans = cur = 0

    for _ in range(int(input())):
        p1, p2 = map(int, input().split())
        cur += p1 - p2
        ans = min(ans, cur)

    print(-ans)
