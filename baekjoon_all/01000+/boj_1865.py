# Solve 2025-09-21

import sys

input = lambda: sys.stdin.readline().rstrip()

def bellman_ford(n, edges):
    min_dist = [0] * (n + 1)

    for _ in range(n - 1):
        for s, e, t in edges:
            if min_dist[s] + t < min_dist[e]:
                min_dist[e] = min_dist[s] + t

    for s, e, t in edges:
        if min_dist[s] + t < min_dist[e]:
            return False

    return True


for _ in range(int(input())):
    n, m, w = map(int, input().split())
    edges = []

    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))

    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))

    ans = bellman_ford(n, edges)
    print("NO" if ans else "YES")
