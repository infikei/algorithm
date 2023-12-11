# Solve 2023-03-02
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = sorted(map(int, input().split()), reverse = True)
ans = 0

for i in range(n):
    ans = max(ans, li[i] + i)

ans += 2
print(ans)
