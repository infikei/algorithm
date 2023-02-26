# Solve 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
MAX_SIZE = 101
graph = [[False] * MAX_SIZE for _ in range(MAX_SIZE)]

for _ in range(n):
    x, y = map(int, input().split())
    for nx in range(x, x + 10):
        for ny in range(y, y + 10):
            graph[nx][ny] = True

ans = 0
for x in range(MAX_SIZE):
    ans += graph[x].count(True)

print(ans)
