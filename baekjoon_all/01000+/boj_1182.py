# Solve 2023-03-29

import sys

input = lambda : sys.stdin.readline().rstrip()

def dfs(depth = 0, val = 0, cnt = 0):
    if depth == n:
        if val == s and cnt > 0:
            return 1
        return 0

    res = dfs(depth + 1, val, cnt)
    res += dfs(depth + 1, val + li[depth], cnt + 1)
    return res

n, s = map(int, input().split())
li = list(map(int, input().split()))
ans = dfs()

print(ans)
