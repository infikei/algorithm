# Solve 2025-09-20

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
board = [list(map(int, input().split())) for _ in range(2)]
memo = [board[0][0], float("-inf"), board[0][0] + board[1][0]]

for i in range(1, n):
    memo = [
        max(memo[0], memo[2]) + board[0][i],
        max(memo[1], memo[2]) + board[1][i],
        max(memo[0], memo[1], memo[2]) + board[0][i] + board[1][i]
    ]

print(max(memo[1], memo[2]))
