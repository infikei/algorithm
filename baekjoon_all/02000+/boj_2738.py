# Solve 2023-02-26
# Update 2024-01-28

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(m):
        print(a[i][j] + b[i][j], end=" ")

    print()
