# Solve 2023-03-13

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = [int(input()) for _ in range(n)]

li.sort(reverse=True)

ans = 0
for i in range(n):
    ans = max(ans, li[i] * (i + 1))
print(ans)
