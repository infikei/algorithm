# Solve 2025-09-13

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

def count_area(board, n, color_dict):
    dd = [(0, -1), (0, 1), (-1, 0), (1, 0)]
    bfs_que = deque()
    visited = [[False] * n for _ in range(n)]
    area_cnt = 0

    for x in range(n):
        for y in range(n):
            if visited[x][y]:
                continue

            area_cnt += 1
            color = color_dict[board[x][y]]
            visited[x][y] = True
            bfs_que.append((x, y))

            while bfs_que:
                xx, yy = bfs_que.popleft()

                for dx, dy in dd:
                    nx = xx + dx
                    ny = yy + dy

                    if nx < 0 or nx >= n or ny < 0 or ny >= n:
                        continue

                    if visited[nx][ny] or color_dict[board[nx][ny]] != color:
                        continue

                    visited[nx][ny] = True
                    bfs_que.append((nx, ny))

    return area_cnt


n = int(input())
board = [input() for _ in range(n)]
area_cnt = count_area(board, n, {"R": "R", "G": "G", "B": "B"})
area_cnt2 = count_area(board, n, {"R": "R", "G": "R", "B": "B"})
print(area_cnt, area_cnt2)
