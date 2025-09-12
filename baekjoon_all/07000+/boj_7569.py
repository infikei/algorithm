# Solve 2025-09-10

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

m, n, h = map(int, input().split())
board = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
dz = [0, 0, 0, 0, -1, 1]
dx = [0, 0, -1, 1, 0, 0]
dy = [-1, 1, 0, 0, 0, 0]
not_ripe_cnt = 0
bfs_que = deque()

for z in range(h):
    for x in range(n):
        not_ripe_cnt += board[z][x].count(0)

        for y in range(m):
            if board[z][x][y] == 1:
                bfs_que.append((z, x, y))

day = 0

while bfs_que and not_ripe_cnt:
    day += 1
    iter = len(bfs_que)

    while iter:
        iter -= 1
        cur = bfs_que.popleft()

        for d in range(6):
            nz = cur[0] + dz[d]
            nx = cur[1] + dx[d]
            ny = cur[2] + dy[d]

            if (nz >= 0 and nz < h and nx >= 0 and nx < n
                and ny >= 0 and ny < m and board[nz][nx][ny] == 0):
                board[nz][nx][ny] = 1
                bfs_que.append((nz, nx, ny))
                not_ripe_cnt -= 1

print(-1 if not_ripe_cnt else day)
