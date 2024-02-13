# Solve 2024-02-12

import sys

input = lambda : sys.stdin.readline().rstrip()

prev, cur = 0, 1

for i in range(int(input()) - 1):
    prev, cur = cur, prev + cur

print(cur)
