# Solve 2026-06-14

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs(x, y):
    ret = 0
    que = deque()

    board[x][y] = 1
    que.append((x, y))
    ret += 1

    while que:
        cx, cy = que.popleft()

        for d in range(4):
            nx = cx + dx[d]
            ny = cy + dy[d]

            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                board[nx][ny] = 1
                que.append((nx, ny))
                ret += 1

    return ret


m, n, k = map(int, input().split())
board = [[0] * m for _ in range(n)]

for _ in range(k):
    xl, yl, xh, yh = map(int, input().split())

    for x in range(xl, xh):
        for y in range(yl, yh):
            board[x][y] = 1

area = []

for x in range(n):
    for y in range(m):
        if board[x][y] == 0:
            area.append(bfs(x, y))

area.sort()
print(len(area))
print(*area)
