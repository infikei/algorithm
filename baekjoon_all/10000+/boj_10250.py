# Solve 2022-05-21
# Update 2025-07-20

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    h, w, n = map(int, input().split())
    print(((n - 1) % h + 1) * 100 + ((n - 1) // h + 1))
