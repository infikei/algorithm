# Solve 2025-10-04

import sys
sys.setrecursionlimit(10 ** 6)

input = lambda: sys.stdin.readline().rstrip()

def dfs(cur):
    max_depth_list = [0, 0]
    max_len = 0

    for nxt, w in tree[cur]:
        d, l = dfs(nxt)
        max_depth_list.append(d + w)
        max_len = max(max_len, l)

    max_depth_list.sort(reverse=True)
    return max_depth_list[0], max(max_depth_list[0] + max_depth_list[1], max_len)


n = int(input())
tree = [[] for _ in range(n + 1)]

for _ in range(1, n):
    par, child, w = map(int, input().split())
    tree[par].append((child, w))

max_depth, max_len = dfs(1)
print(max_len)
