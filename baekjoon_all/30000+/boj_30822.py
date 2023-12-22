# Solve 2023-12-22

from collections import Counter

_ = input()
cnt = Counter(input())

ans = min(map(lambda c: cnt[c], list("uospc")))
print(ans)
