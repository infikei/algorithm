# Solve 2023-03-02
# Update 2023-09-05

import sys
from heapq import heappush, heappop

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
heap = []

for _ in range(n):
    x = int(input())

    if x == 0:
        if len(heap) == 0:
            print(0)
        else:
            res = heappop(heap)
            print(res[0] * res[1])
    else:
        heappush(heap, (abs(x), x // abs(x)))
