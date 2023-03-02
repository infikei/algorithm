# Solve 2023-03-02

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = sorted(map(int, input().split()), reverse=True)

ans = 0
for i in range(n):
    ans = max(ans, li[i] + i)
ans += 2
print(ans)
