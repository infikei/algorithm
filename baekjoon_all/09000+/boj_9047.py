# Solve 2025-08-29

import sys

input = lambda: sys.stdin.readline().strip()

def kaprekar(n):
    li = list("%04d" % n)
    max_n = int(''.join(sorted(li, reverse=True)))
    min_n = int(''.join(sorted(li)))
    return max_n - min_n


for _ in range(int(input())):
    n = int(input())
    cnt = 0

    while n != 6174:
        n = kaprekar(n)
        cnt += 1

    print(cnt)
