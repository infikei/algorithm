# Solve 2023-03-01

import sys
from collections import deque

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
dq = deque([i for i in range(1, n + 1)])
targets = list(map(int, input().split()))

ans = 0
for target in targets:
    tmp = 0

    while dq[0] != target:
        dq.append(dq.popleft())
        tmp += 1
    tmp2 = len(dq) - tmp
    if tmp > tmp2:
        tmp = tmp2

    dq.popleft()
    ans += tmp

print(ans)
