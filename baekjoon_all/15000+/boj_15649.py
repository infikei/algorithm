# Solve 2022-05-29
# Update 2024-01-30

import sys

input = lambda : sys.stdin.readline().rstrip()

def dfs():
    if len(seq) == m:
        print(' '.join(map(str, seq)))
        return

    for i in range(1, n + 1):
        if not selected[i]:
            selected[i] = True
            seq.append(i)
            dfs()
            seq.pop()
            selected[i] = False


n, m = map(int, input().split())
selected = [False] * (n + 1)
seq = []

dfs()
