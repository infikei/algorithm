# Solve 2023-03-13
# Update 2023-12-19

import sys

input = lambda : sys.stdin.readline().rstrip()

n = sorted(map(int, input()), reverse=True)

if n[-1] == 0 and sum(n) % 3 == 0:
    print(*n, sep="")
else:
    print(-1)
