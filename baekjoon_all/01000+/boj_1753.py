# Solve 2025-09-19

import sys
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()

def dijkstra(start_node, v, adj):
    min_dist = [float("inf")] * (v + 1)
    min_dist[start_node] = 0
    heap = [(0, start_node)]

    while heap:
        cur = heappop(heap)

        if cur[0] > min_dist[cur[1]]:
            continue

        for nxt in adj[cur[1]]:
            n_dist = cur[0] + nxt[0]

            if n_dist < min_dist[nxt[1]]:
                min_dist[nxt[1]] = n_dist
                heappush(heap, (n_dist, nxt[1]))

    return min_dist


v, e = map(int, input().split())
k = int(input())
adj = [[] for _ in range(v + 1)]

for _ in range(e):
    u1, u2, w = map(int, input().split())
    adj[u1].append((w, u2))

min_dist = dijkstra(k, v, adj)
min_dist = list(map(lambda x: "INF" if x == float("inf") else x, min_dist))
print(*min_dist[1:], sep="\n")
