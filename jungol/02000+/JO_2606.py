# Solve 2026-06-08

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

m, n, h = map(int, input().split())
board = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
not_riped = 0
que = deque()

for z in range(h):
    for x in range(n):
        not_riped += board[z][x].count(0)

        for y in range(m):
            if board[z][x][y] == 1:
                que.append((z, x, y))

dz = [0, 0, 0, 0, -1, 1]
dx = [0, 0, -1, 1, 0, 0]
dy = [-1, 1, 0, 0, 0, 0]
days = -1

while que:
    days += 1
    iter = len(que)

    for _ in range(iter):
        z, x, y = que.popleft()

        for d in range(6):
            nz = z + dz[d]
            nx = x + dx[d]
            ny = y + dy[d]

            if 0 <= nz < h and 0 <= nx < n and 0 <= ny < m and board[nz][nx][ny] == 0:
                board[nz][nx][ny] = 1
                que.append((nz, nx, ny))
                not_riped -= 1

print(-1 if not_riped else days)
