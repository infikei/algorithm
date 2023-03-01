# Solve 2023-03-01

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
graph = [input() for _ in range(n)]

ans = 0
for row in range(n):
    tmp = 0
    for col in range(n):
        if graph[row][col] == ".":
            tmp += 1
        else:
            if tmp > 1:
                ans += 1
            tmp = 0
    if tmp > 1:
        ans += 1

ans2 = 0
for col in range(n):
    tmp = 0
    for row in range(n):
        if graph[row][col] == ".":
            tmp += 1
        else:
            if tmp > 1:
                ans2 += 1
            tmp = 0
    if tmp > 1:
        ans2 += 1

print(ans, ans2)
