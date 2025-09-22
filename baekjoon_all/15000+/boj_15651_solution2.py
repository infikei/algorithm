# Solve 2022-05-29
# Update 2025-09-22

import sys
from itertools import product

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())

for selected_indices in product(range(1, n + 1), repeat=m):
    print(*selected_indices)
