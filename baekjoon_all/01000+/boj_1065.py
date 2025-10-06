# Solve 2022-05-19
# Update 2025-10-05

import sys

input = lambda: sys.stdin.readline().rstrip()

hansu = [0] * 1001

for d in range(1, 100):
    hansu[d] = 1

for d in range(100, 1000):
    if d // 10 % 10 * 2 == d // 100 + d % 10:
        hansu[d] = 1

n = int(input())
print(sum(hansu[1:n + 1]))
