# Solve 2025-09-07
# Update 2025-09-22

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

def dfs(cur, adj, visited, dfs_output):
    visited[cur] = True
    dfs_output.append(cur)

    for nxt in adj[cur]:
        if not visited[nxt]:
            dfs(nxt, adj, visited, dfs_output)


def bfs(v, adj, visited, bfs_output):
    que = deque()
    visited[v] = True
    que.append(v)
    bfs_output.append(v)

    while que:
        cur = que.popleft()

        for nxt in adj[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                que.append(nxt)
                bfs_output.append(nxt)


n, m, v = map(int, input().split())
adj = [[] for _ in range(n + 1)]

for _ in range(m):
    u1, u2 = map(int, input().split())
    adj[u1].append(u2)
    adj[u2].append(u1)

for li in adj:
    li.sort()

visited = [False] * (n + 1)
dfs_output = []
dfs(v, adj, visited, dfs_output)
print(*dfs_output)

visited = [False] * (n + 1)
bfs_output = []
bfs(v, adj, visited, bfs_output)
print(*bfs_output)
