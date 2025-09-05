# Solve 2022-05-30
# Update 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

points = [tuple(map(int, input().split())) for _ in range(int(input()))]
points.sort()

for p in points:
    print(*p)
