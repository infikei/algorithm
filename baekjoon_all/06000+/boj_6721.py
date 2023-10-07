# Solve 2023-10-07

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    li = input().split()
    ans = sum(map(lambda x: int("".join(reversed(x))), li))
    ans = int("".join(reversed(str(ans))))
    print(ans)
