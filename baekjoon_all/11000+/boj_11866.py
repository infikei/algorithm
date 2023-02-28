# Solve 2023-02-28

from collections import deque

n, k = map(int, input().split())
q = deque([i for i in range(1, n + 1)])
ans = []

for i in range(n):
    for _ in range(k - 1):
        q.append(q.popleft())
    ans.append(q.popleft())

print("<", ", ".join(map(str, ans)), ">", sep="")
