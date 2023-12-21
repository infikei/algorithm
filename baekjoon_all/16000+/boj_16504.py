# Solve 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
ans = 0

for _ in range(n):
    ans += sum(map(int, input().split()))

print(ans)
