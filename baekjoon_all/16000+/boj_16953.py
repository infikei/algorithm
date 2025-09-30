# Solve 2025-09-28

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

def bfs(a, b):
    que = deque()
    que.append((a, 1))

    while que:
        v, depth = que.popleft()

        for nxt_v in [v * 2, v * 10 + 1]:
            if nxt_v < b:
                que.append((nxt_v, depth + 1))
            elif nxt_v == b:
                return depth + 1

    return -1


a, b = map(int, input().split())
print(bfs(a, b))
