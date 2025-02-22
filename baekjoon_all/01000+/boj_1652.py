# Solve 2023-03-01
# Update 2025-02-21

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
board = [input() for _ in range(n)]
ans = 0

for x in range(n):
    cur = 0

    for y in range(n):
        if board[x][y] == ".":
            cur += 1
        else:
            if cur >= 2:
                ans += 1

            cur = 0

    if cur >= 2:
        ans += 1

ans2 = 0

for y in range(n):
    cur = 0

    for x in range(n):
        if board[x][y] == ".":
            cur += 1
        else:
            if cur >= 2:
                ans2 += 1

            cur = 0

    if cur >= 2:
        ans2 += 1

print(ans, ans2)
