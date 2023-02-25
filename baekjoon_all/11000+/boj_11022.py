# Solve 2022-05-16
# Update 2023-02-22

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for ti in range(1, t + 1):
    a, b = map(int, input().split())
    print("Case #%d: %d + %d = %d" % (ti, a, b, a + b))
