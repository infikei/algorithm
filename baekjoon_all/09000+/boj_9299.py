# Solve 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

for ti in range(1, int(input()) + 1):
    n, *li = map(int, input().split())
    li.pop()

    for i in range(n):
        li[i] *= n - i

    print("Case %d: %d %s" % (ti, n - 1, " ".join(map(str, li))))
