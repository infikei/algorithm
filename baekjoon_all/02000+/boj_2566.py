# Solve 2023-02-26
# Update 2024-01-28

import sys

input = lambda : sys.stdin.readline().rstrip()

max_num = row_of_max_num = col_of_max_num = -1

for row in range(9):
    nums = list(map(int, input().split()))

    for col in range(9):
        if nums[col] > max_num:
            max_num = nums[col]
            row_of_max_num = row
            col_of_max_num = col

print(max_num)
print(row_of_max_num + 1, col_of_max_num + 1)
