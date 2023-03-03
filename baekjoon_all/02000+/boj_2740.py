# Solve 2023-03-03

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
m, k = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(m)]

ans = [[0] * k for _ in range(n)]
for row in range(n):
    for col in range(k):
        for idx in range(m):
            ans[row][col] += a[row][idx] * b[idx][col]

for row in range(n):
    print(*ans[row])
