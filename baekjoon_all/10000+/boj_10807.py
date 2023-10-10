# Solve 2023-02-23
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
nums = list(map(int, input().split()))
v = int(input())
ans = 0

for num in nums:
    if num == v:
        ans += 1

print(ans)
