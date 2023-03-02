# Solve 2023-03-02

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
            print(heappop(heap))
    else:
        heappush(heap, x)
