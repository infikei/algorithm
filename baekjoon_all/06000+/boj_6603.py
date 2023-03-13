# Solve 2023-03-13

import sys

input = lambda : sys.stdin.readline().rstrip()

def dfs(depth = 0, cur = 0):
    if depth == 6:
        print(*ans)
        return
    for i in range(cur, k):
        ans[depth] = s[i]
        dfs(depth + 1, i + 1)

ans = [0] * 6

first_iter = True
while True:
    if first_iter:
        first_iter = False
    else:
        print()

    s = list(map(int, input().split()))
    if s[0] == 0:
        break

    k, *s = s
    dfs()
