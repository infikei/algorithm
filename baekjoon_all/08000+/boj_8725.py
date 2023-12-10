# Solve 2023-12-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
ans = sum([max(0, *map(int, input().split())) for _ in range(n)])

print(ans)
