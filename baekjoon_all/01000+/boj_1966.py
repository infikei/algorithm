# Solve 2023-03-01

import sys
from collections import deque, Counter

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    q_val = deque(map(int, input().split()))
    q_idx = deque([i for i in range(n)])
    cnt = Counter(q_val)

    ans = 0
    cur_val = 9
    while cnt[cur_val] == 0:
        cur_val -= 1

    while True:
        now_val = q_val.popleft()
        now_idx = q_idx.popleft()

        if now_val == cur_val:
            ans += 1
            if now_idx == m:
                break
            cnt[cur_val] -= 1
            while cnt[cur_val] == 0:
                cur_val -= 1
        else:
            q_val.append(now_val)
            q_idx.append(now_idx)

    print(ans)
