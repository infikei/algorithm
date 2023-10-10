# Solve 2022-05-16
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n, x = map(int, input().split())
nums = list(map(int, input().split()))
ans = filter(lambda num: num < x, nums)

print(*ans)
