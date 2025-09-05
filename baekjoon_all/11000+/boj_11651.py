# Solve 2022-06-01
# Update 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

points = [tuple(map(int, input().split())) for _ in range(int(input()))]
points.sort(key=lambda x: (x[1], x[0]))

for p in points:
    print(*p)
