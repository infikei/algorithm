# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

exam_ans = [1, 2, 3, 4, 5] * 2
n = int(input())

for k in range(1, n + 1):
    cnt = 0
    li = list(map(int, input().split()))
    for i in range(10):
        if li[i] == exam_ans[i]:
            cnt += 1

    if cnt == 10:
        print(k)
