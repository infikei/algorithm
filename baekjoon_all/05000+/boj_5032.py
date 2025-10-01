# Solve 2025-09-30

import sys

input = lambda: sys.stdin.readline().rstrip()

e, f, c = map(int, input().split())
bottle = e + f
cnt = 0

while bottle >= c:
    cnt += bottle // c
    bottle = bottle // c + bottle % c

print(cnt)
