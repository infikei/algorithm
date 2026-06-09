# Solve 2026-06-08

import sys

input = lambda: sys.stdin.readline().rstrip()

li = list(map(int, input().split()))
del li[1]
del li[1]
del li[1]
print(li)
