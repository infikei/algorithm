# Solve 2022-06-01
# Update 2023-06-07

import sys

input = lambda : sys.stdin.readline().rstrip()

def dfs(n, row = 0):
    if row == n:
        return 1

    res = 0
    for col in range(n):
        queens[row] = col
        for i in range(row):
            if queens[i] == queens[row] or abs(queens[i] - queens[row]) == (row - i):
                break
        else:
            res += dfs(n, row + 1)

    return res


n = int(input())
queens = [0] * n
print(dfs(n))
