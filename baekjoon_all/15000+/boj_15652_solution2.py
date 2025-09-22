# Solve 2022-05-29
# Update 2025-09-22

import sys
from itertools import combinations_with_replacement

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())

for selected_indices in combinations_with_replacement(range(1, n + 1), m):
    print(*selected_indices)
