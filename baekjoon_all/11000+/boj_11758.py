# Solve 2023-03-15

import sys

input = lambda : sys.stdin.readline().rstrip()

def ccw(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1])

pt = [list(map(int, input().split())) for _ in range(3)]
ans = ccw(*pt)
if ans > 0:
    print(1)
elif ans < 0:
    print(-1)
else:
    print(0)
