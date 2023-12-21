# Solve 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

d1 = int(input())
d2 = int(input())
ans = (d1 + d2 * 3.141592) * 2
print(f"{ans:.8f}")
