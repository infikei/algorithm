# Solve 2026-06-08

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

m, n = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
not_riped = 0
que = deque()

for x in range(n):
    not_riped += board[x].count(0)

    for y in range(m):
        if board[x][y] == 1:
            que.append((x, y))

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
days = -1

while que:
    days += 1
    iter = len(que)

    for _ in range(iter):
        x, y = que.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                board[nx][ny] = 1
                que.append((nx, ny))
                not_riped -= 1

print(-1 if not_riped else days)
