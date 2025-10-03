# Solve 2023-03-04
# Update 2025-10-03

import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
board = [[0] * (n + 1)] + [[0] + list(map(int, input().split())) for _ in range(n)]

for x in range(1, n + 1):
    for y in range(1, n + 1):
        board[x][y] += board[x][y - 1] + board[x - 1][y] - board[x - 1][y - 1]

for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    x1 -= 1
    y1 -= 1
    print(board[x2][y2] - board[x2][y1] - board[x1][y2] + board[x1][y1])
