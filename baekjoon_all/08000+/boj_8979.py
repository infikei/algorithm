# Solve 2023-03-01

import sys

input = lambda : sys.stdin.readline().rstrip()

n, k = map(int, input().split())
li = []
k_val = (0, 0, 0)

for _ in range(n):
    x, a, b, c = map(int, input().split())
    li.append((a, b, c))
    if x == k:
        k_val = (a, b, c)

li.sort(reverse=True)
print(li.index(k_val) + 1)
