# Solve 2023-11-24

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
ans = sum([int(input()) for _ in range(n)])

print(ans)
