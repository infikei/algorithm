# Solve 2024-05-10

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
c = sorted([int(input()) for _ in range(n)], reverse=True)
ans = 0

for i in range(0, n, 3):
    ans += c[i]

    if i + 1 < n:
        ans += c[i + 1]

print(ans)
