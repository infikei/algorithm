# Solve 2023-03-17

import sys

input = lambda : sys.stdin.readline().rstrip()

now_time = list(map(int, input().split(":")))
complete_time = list(map(int, input().split(":")))

ans = [complete_time[i] - now_time[i] for i in range(3)]

if ans[2] < 0:
    ans[2] += 60
    ans[1] -= 1

if ans[1] < 0:
    ans[1] += 60
    ans[0] -= 1

if ans[0] < 0:
    ans[0] += 24

print("%02d:%02d:%02d" % (ans[0], ans[1], ans[2]))
