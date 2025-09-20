# Solve 2025-09-18

import sys
sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()

def recur(depth, color, n, costs, memo):
    if depth == n:
        return 0

    if memo[depth][color] != -1:
        return memo[depth][color]

    ret = 1000000000

    for n_color in range(3):
        if n_color != color:
            nxt_ret = costs[depth][color] + recur(depth + 1, n_color, n, costs, memo)
            ret = min(ret, nxt_ret)

    memo[depth][color] = ret
    return ret


n = int(input())
costs = [list(map(int, input().split())) for _ in range(n)]
memo = [[-1] * 3 for _ in range(n)]

for color in range(3):
    recur(0, color, n, costs, memo)

print(min(memo[0]))
