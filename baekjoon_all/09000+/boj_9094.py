# Solve 2023-03-23
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = 0

    for a in range(1, n):
        tmp = a * a + m

        for b in range(a + 1, n):
            if (tmp + b * b) % (a * b) == 0:
                ans += 1

    print(ans)
