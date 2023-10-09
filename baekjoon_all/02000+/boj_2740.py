# Solve 2023-03-03
# Update 2023-10-09

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
mat_a = [list(map(int, input().split())) for _ in range(n)]

m, k = map(int, input().split())
mat_b = [list(map(int, input().split())) for _ in range(m)]

mat_ans = [[0] * k for _ in range(n)]

for row in range(n):
    for col in range(k):
        for idx in range(m):
            mat_ans[row][col] += mat_a[row][idx] * mat_b[idx][col]

for row in range(n):
    print(*mat_ans[row])
