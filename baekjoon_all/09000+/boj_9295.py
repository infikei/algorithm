# Solve 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

for ti in range(1, int(input()) + 1):
    print("Case %d: %d" % (ti, sum(map(int, input().split()))))
