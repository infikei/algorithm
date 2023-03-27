# Solve 2023-03-26

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = list(map(int, input().split()))

ans = 1
insc_cnt, desc_cnt = 1, 1
for i in range(1, n):
    if li[i - 1] <= li[i]:
        insc_cnt += 1
        if insc_cnt > ans:
            ans = insc_cnt
    else:
        insc_cnt = 1

    if li[i - 1] >= li[i]:
        desc_cnt += 1
        if desc_cnt > ans:
            ans = desc_cnt
    else:
        desc_cnt = 1

print(ans)
