# Solve 2023-03-02
# Update 2025-09-11

import sys
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()

heap = []

for _ in range(int(input())):
    x = int(input())

    if x == 0:
        if heap:
            print(heappop(heap)[1])
        else:
            print(0)
    else:
        heappush(heap, (abs(x), x))
