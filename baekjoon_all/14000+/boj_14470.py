# Solve 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

a, b, c, d, e = [int(input()) for _ in range(5)]
ans = 0
if a > 0:
    ans = (b - a) * e
else:
    ans = b * e + d - a * c

print(ans)
