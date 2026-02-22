# Solve 2026-02-16

import sys

input = lambda: sys.stdin.readline().rstrip()

memo = [0, 1, 1]

for i in range(3, 491):
    memo.append(memo[-2] + memo[-1])

while (h := int(input())) != -1:
    print('Hour %d: %d cow(s) affected' % (h, memo[h]))
