# Solve 2025-09-28

import sys

input = lambda: sys.stdin.readline().rstrip()

def solution(a, b):
    ret = 1

    while b > a:
        if b % 10 == 1:
            b //= 10
            ret += 1
        elif b % 2 == 0:
            b //= 2
            ret += 1
        else:
            return -1

    return ret if a == b else -1


a, b = map(int, input().split())
print(solution(a, b))
