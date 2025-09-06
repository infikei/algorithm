# Solve 2022-05-26
# Update 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
board = [input() for _ in range(n)]
ans = 64

for i in range(n - 7):
    for j in range(m - 7):
        cnt = 0

        for x in range(i, i + 8):
            for y in range(j, j + 8):
                if board[x][y] == "BW"[(x + y) % 2]:
                    cnt += 1

        ans = min(ans, cnt, 64 - cnt)

print(ans)
