# Solve 2023-12-14

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
p = int(input())
ans = sum(filter(lambda x: x > 0, map(lambda x: int(x) ** p, input().split())))
print(ans)
