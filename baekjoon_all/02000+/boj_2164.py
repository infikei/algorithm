# Solve 2023-02-28

import collections

n = int(input())
dq = collections.deque([i for i in range(1, n + 1)])

for _ in range(n - 1):
    dq.popleft()
    dq.append(dq.popleft())

print(dq.popleft())
