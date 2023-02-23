# Solve 2022-05-16
# Update 2023-02-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n, x = map(int, input().split())
li = list(map(int, input().split()))
ans = filter(lambda a: a < x, li)

print(*ans)
