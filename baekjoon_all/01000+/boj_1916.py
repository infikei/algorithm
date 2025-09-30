# Solve 2025-09-27

import sys
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()

def dijkstra(start_node, n, adj):
    min_dist = [float("inf")] * (n + 1)
    min_dist[start_node] = 0
    pq = []
    heappush(pq, (0, start_node))

    while pq:
        u_dist, u = heappop(pq)

        if u_dist > min_dist[u]:
            continue

        for v, w in adj[u]:
            v_dist = u_dist + w

            if v_dist < min_dist[v]:
                min_dist[v] = v_dist
                heappush(pq, (v_dist, v))

    return min_dist


n = int(input())
m = int(input())
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))

start_node, end_node = map(int, input().split())
min_dist = dijkstra(start_node, n, adj)
print(min_dist[end_node])
