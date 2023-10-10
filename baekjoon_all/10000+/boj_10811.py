# Solve 2023-02-24
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
baskets = [i for i in range(n + 1)]

for _ in range(m):
    left, right = map(int, input().split())

    baskets[left:right + 1] = reversed(baskets[left:right + 1])

print(*baskets[1:])
