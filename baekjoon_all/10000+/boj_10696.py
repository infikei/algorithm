# Solve 2025-02-25

import sys

input = lambda : sys.stdin.readline().rstrip()

for ti in range(1, int(input()) + 1):
    n, x = map(int, input().split())
    print("Case %d: %d" % (ti, n % x))
