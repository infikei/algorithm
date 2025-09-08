# Solve 2025-09-08

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
fruits = list(map(int, input().split()))
max_len = 0

for i in range(10):
    for j in range(i + 1, 10):
        cur_len = 0

        for k in range(n):
            if fruits[k] in [i, j]:
                cur_len += 1
            else:
                max_len = max(max_len, cur_len)
                cur_len = 0

        max_len = max(max_len, cur_len)

print(max_len)
