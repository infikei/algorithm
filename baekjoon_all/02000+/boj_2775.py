# Solve 2022-05-23
# Update 2025-01-28

import sys

input = lambda : sys.stdin.readline().rstrip()

building = [list(range(15)) for _ in range(15)]

for i in range(1, 15):
    for j in range(1, 15):
        building[i][j] = building[i][j - 1] + building[i - 1][j]

for _ in range(int(input())):
    k = int(input())
    n = int(input())
    print(building[k][n])
