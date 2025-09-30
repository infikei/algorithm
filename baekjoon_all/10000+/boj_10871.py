# Solve 2022-05-16
# Update 2025-09-29

import sys

input = lambda: sys.stdin.readline().rstrip()

n, x = map(int, input().split())
print(*filter(lambda v: v < x, map(int, input().split())))
