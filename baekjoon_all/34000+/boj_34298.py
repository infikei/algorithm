# Solve 2025-11-08

import sys

input = lambda: sys.stdin.readline().rstrip()

r, s, n = map(int, input().split())
a = list(map(int, input().split()))

if r:
    for i in range(n):
        r = (r - a[i]) % s
        if r == 0:
            print(i + 1)
            break
    else:
        print(-1)
else:
    print(0)
