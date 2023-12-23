# Solve 2023-12-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n, a = map(int, input().split())
ans = sum([int(x) // a for x in input().split()])
print(ans)
