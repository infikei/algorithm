# Solve 2025-01-26

import sys
from math import log, pi, factorial

input = lambda : sys.stdin.readline().rstrip()

# 스털링 근사 공식을 활용하여 log(n!)의 근삿값을 구한다.
def approximate_log_factorial(n):
    return log(2 * pi * n) / 2 + n * (log(n) - 1)

def solution(fac):
    for i in range(1, 21):
        if fac == factorial(i):
            return i

    logFac = log(fac)
    low = 20
    high = 300000

    while low + 2 < high:
        mid1 = (low * 2 + high) // 3
        mid2 = (low + high * 2) // 3
        logFacMid1 = approximate_log_factorial(mid1)
        logFacMid2 = approximate_log_factorial(mid2)

        if abs(logFac - logFacMid1) < abs(logFac - logFacMid2):
            high = mid2
        else:
            low = mid1

    return low + 1

fac = int(input())
ans = solution(fac)
print(ans)
