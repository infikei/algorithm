# Solve 2022-05-22
# Update 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

n, m, k = map(int, input().split())
print(k // m, k % m)
