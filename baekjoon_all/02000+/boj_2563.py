# Solve 2023-02-26
# Update 2024-01-28

import sys

input = lambda : sys.stdin.readline().rstrip()

board = [[False] * 100 for _ in range(100)]
n = int(input())

for _ in range(n):
    x, y = map(int, input().split())

    for nx in range(x, x + 10):
        for ny in range(y, y + 10):
            board[nx][ny] = True

print(sum(map(lambda board_row: board_row.count(True), board)))
