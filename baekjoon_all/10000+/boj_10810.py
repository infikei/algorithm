# Solve 2023-02-23
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
baskets = [0] * (n + 1)

for _ in range(m):
    left, right, num = map(int, input().split())

    for i in range(left, right + 1):
        baskets[i] = num

print(*baskets[1:])
