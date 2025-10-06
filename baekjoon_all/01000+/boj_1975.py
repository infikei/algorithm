# Solve 2025-10-06

import sys
from math import sqrt, floor

input = lambda: sys.stdin.readline().rstrip()

def get_div_cnt(n, q):
    if q == 1:
        return 0

    ret = 0

    while n % q == 0:
        n //= q
        ret += 1

    return ret


def solution(n):
    if memo[n] != -1:
        return memo[n]

    ret = 0

    for i in range(1, floor(sqrt(n)) + 1):
        if n % i:
            continue

        ret += get_div_cnt(n, i)

        if (j := n // i) != i:
            ret += get_div_cnt(n, j)

    memo[n] = ret
    return ret


memo = [-1] * 1001

for _ in range(int(input())):
    n = int(input())
    print(solution(n))
