# Solve 2023-03-17
# Update 2023-09-03

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n, c = map(int, input().split())

    ans = (n - 1) // c + 1

    print(ans)
