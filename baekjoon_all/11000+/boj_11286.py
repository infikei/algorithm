# Solve 2023-03-02

import sys
from heapq import heappush, heappop

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

heap = []
for _ in range(n):
    x = int(input())

    if x == 0:
        if heap:
            res = heappop(heap)
            print(res[0] * res[1])
        else:
            print(0)
    else:
        heappush(heap, (abs(x), x // abs(x)))
