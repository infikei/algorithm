# Solve 2023-03-01
# Update 2023-10-14

import sys
from collections import deque

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
targets = map(int, input().split())

dque = deque(range(1, n + 1))
ans = 0

for target in targets:
    cnt = 0

    while dque[0] != target:
        dque.append(dque.popleft())
        cnt += 1

    ans += min(cnt, len(dque) - cnt)

    dque.popleft()

print(ans)
