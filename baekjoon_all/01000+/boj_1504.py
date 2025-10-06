# Solve 2025-10-05

import sys
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()

def dijkstra(start_node, n):
    min_dist = [float("inf")] * (n + 1)
    min_dist[start_node] = 0
    heap = [(0, start_node)]

    while heap:
        cur_dist, cur = heappop(heap)

        if cur_dist > min_dist[cur]:
            continue

        for nxt, w in adj[cur]:
            nxt_dist = cur_dist + w

            if nxt_dist < min_dist[nxt]:
                min_dist[nxt] = nxt_dist
                heappush(heap, (nxt_dist, nxt))

    return min_dist


n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj[v].append((u, w))

v1, v2 = map(int, input().split())

min_dist_v1 = dijkstra(v1, n)
min_dist_v2 = dijkstra(v2, n)
r1 = min_dist_v1[1] + min_dist_v1[v2] + min_dist_v2[n]
r2 = min_dist_v2[1] + min_dist_v1[v2] + min_dist_v1[n]
r = min(r1, r2)
print(-1 if r == float("inf") else r)
