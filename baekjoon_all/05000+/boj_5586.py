# Solve 2023-03-14

import sys

input = lambda : sys.stdin.readline().rstrip()

s = input()

targets = ["JOI", "IOI"]
cnt = [0] * 2
for i in range(2):
    pos = s.find(targets[i])
    while pos != -1:
        cnt[i] += 1
        pos = s.find(targets[i], pos + 1)

print(*cnt, sep="\n")
