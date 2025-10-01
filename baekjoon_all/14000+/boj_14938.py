# Solve 2025-09-30

import sys

input = lambda: sys.stdin.readline().rstrip()

def floyd_warshall(n: int, dist: list[list[int | float]]):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            for k in range(1, n + 1):
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k])


n, m, r = map(int, input().split())
item = list(map(int, ("0 " + input()).split()))
dist = [[float("inf")] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    dist[i][i] = 0

for _ in range(r):
    u, v, w = map(int, input().split())
    dist[u][v] = min(dist[u][v], w)
    dist[v][u] = min(dist[v][u], w)

floyd_warshall(n, dist)

max_item = 0

for i in range(1, n + 1):
    cur_item = 0

    for j in range(1, n + 1):
        if dist[i][j] <= m:
            cur_item += item[j]

    max_item = max(max_item, cur_item)

print(max_item)
