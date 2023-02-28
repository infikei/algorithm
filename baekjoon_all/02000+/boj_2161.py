# Solve 2023-02-28

import collections

n = int(input())
dq = collections.deque([i for i in range(1, n + 1)])

ans = ""
while True:
    ans += str(dq.popleft()) + " "
    if len(dq) == 0:
        break
    dq.append(dq.popleft())

print(ans[:-1])
