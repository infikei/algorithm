# Solve 2026-02-17

import sys

input = lambda: sys.stdin.readline().rstrip()

memo = [0, 1, 2, 3]

for i in range(4, 36):
    memo.append(sum(memo[-4:]))

for _ in range(int(input())):
    fossil = list(map(int, input().split()))

    if len(fossil) >= 37:
        print('SNAIL')
        continue

    for i in range(len(fossil)):
        if fossil[i] != memo[i]:
            print('SNAIL')
            break
    else:
        print('NAUTILUS')
