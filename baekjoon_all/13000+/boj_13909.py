# Solve 2023-03-24

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
ans = 0
i = 1
while i * i <= n:
    ans += 1
    i += 1

print(ans)
