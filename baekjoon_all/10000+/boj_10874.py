# Solve 2023-03-04
# Update 2023-12-20

import sys

input = lambda : sys.stdin.readline().rstrip()

exam_ans = [1, 2, 3, 4, 5] * 2

for k in range(1, int(input()) + 1):
    student_ans = list(map(int, input().split()))
    cnt = 0

    for i in range(10):
        if student_ans[i] == exam_ans[i]:
            cnt += 1

    if cnt == 10:
        print(k)
