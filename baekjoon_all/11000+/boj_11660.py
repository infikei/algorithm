# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
li = [[0] * (n + 1)] + [[0] + list(map(int, input().split())) for _ in range(n)]
for row in range(1, n + 1):
    for col in range(1, n + 1):
        li[row][col] += li[row][col - 1] + li[row - 1][col] - li[row - 1][col - 1]

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    print(li[x2][y2] - li[x2][y1 - 1] - li[x1 - 1][y2] + li[x1 - 1][y1 - 1])
