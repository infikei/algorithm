# Solve 2023-12-23

import sys
from itertools import product

input = lambda : sys.stdin.readline().rstrip()

_ = input()
dice1 = list(map(int, input().split()))
dice2 = list(map(int, input().split()))
cnt = [0, 0]

for d1, d2 in product(dice1, dice2):
    if d1 > d2:
        cnt[0] += 1
    elif d1 < d2:
        cnt[1] += 1

if cnt[0] > cnt[1]:
    print("first")
elif cnt[0] < cnt[1]:
    print("second")
else:
    print("tie")
