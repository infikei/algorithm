# Solve 2025-10-03

import sys
sys.setrecursionlimit(10 ** 6)

input = lambda: sys.stdin.readline().rstrip()

def dfs(cur, par):
    max_depth_list = [0, 0]
    max_len = 0

    for nxt, w in adj[cur]:
        if nxt == par:
            continue

        nxt_dep, nxt_len = dfs(nxt, cur)
        max_depth_list.append(nxt_dep + w)
        max_len = max(max_len, nxt_len)

    max_depth_list.sort(reverse=True)
    return max_depth_list[0], max(max_depth_list[0] + max_depth_list[1], max_len)


n = int(input())
adj = [[] for _ in range(n + 1)]

for _ in range(n):
    u, *li, _ = map(int, input().split())

    for i in range(0, len(li), 2):
        adj[u].append((li[i], li[i + 1]))

max_depth, max_len = dfs(1, -1)
print(max_len)
