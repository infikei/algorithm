# Solve 2023-03-14

import sys

input = lambda : sys.stdin.readline().rstrip()

a, b = map(int, input().split())
if a > b:
    a, b = b, a

if a == b or a + 1 == b:
    print(0)
else:
    print(b - a - 1)
    print(*range(a + 1, b))
