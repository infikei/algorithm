# Solve 2025-07-15

import sys

input = lambda : sys.stdin.readline().rstrip()

def dfs(x, y):
    if x >= n or y >= n:
        return 0

    if memo[x][y] != -1:
        return memo[x][y]

    num = board[x][y]

    if num == 0:
        return 0

    memo[x][y] = dfs(x, y + num) + dfs(x + num, y)
    return memo[x][y]

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
memo = [[-1] * n for _ in range(n)]
memo[n - 1][n - 1] = 1
print(dfs(0, 0))
