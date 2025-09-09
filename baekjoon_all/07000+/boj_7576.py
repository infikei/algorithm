# Solve 2025-09-09

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

m, n = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
not_ripe_cnt = 0
bfs_que = deque()

for x in range(n):
    not_ripe_cnt += board[x].count(0)

    for y in range(m):
        if board[x][y] == 1:
            bfs_que.append((x, y))

day = 0

while bfs_que and not_ripe_cnt:
    day += 1
    iter = len(bfs_que)

    while iter:
        iter -= 1
        cur = bfs_que.popleft()

        for d in range(4):
            nx = cur[0] + dx[d]
            ny = cur[1] + dy[d]

            if nx >= 0 and nx < n and ny >= 0 and ny < m and board[nx][ny] == 0:
                board[nx][ny] = 1
                bfs_que.append((nx, ny))
                not_ripe_cnt -= 1

print(-1 if not_ripe_cnt else day)
