# Solve 2023-11-18

import sys

input = lambda : sys.stdin.readline().rstrip()

n, k, c, r = map(int, input().split())
base = list(map(int, input().split()))
s = list(map(int, input().split()))
p = list(map(int, input().split()))

stardust = 0
combo = 0
fatigue = 0
skill = [0 for _ in range(k)]

for _ in range(n):
    l = int(input()) - 1

    if stardust == -1:
        continue

    if l == -1:
        combo = 0
        fatigue -= r

        if fatigue < 0:
            fatigue = 0
    else:
        stardust += (100 + combo * c) * (100 + skill[l] * s[l]) * base[l] // 10000
        combo += 1
        skill[l] += 1
        fatigue += p[l]

        if fatigue > 100:
            stardust = -1

print(stardust)
