# Solve 2026-06-08

import sys

input = lambda: sys.stdin.readline().rstrip()

li = list(map(int, input().split()))
li = [li[i] for i in range(2, 6)]
print(li)
