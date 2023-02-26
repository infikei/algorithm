# Solve 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

max_val = max_row_idx = max_col_idx = 0
for row in range(9):
    line = list(map(int, input().split()))
    for col in range(9):
        if line[col] > max_val:
            max_val = line[col]
            max_row_idx = row
            max_col_idx = col

print(max_val)
print(max_row_idx + 1, max_col_idx + 1)
