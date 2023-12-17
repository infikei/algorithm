# Solve 2023-12-16

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    d = int(input())
    ans = 1

    while ans * (ans + 1) <= d:
        ans += 1

    ans -= 1

    print(ans)
