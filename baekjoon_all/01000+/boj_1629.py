# Solve 2025-09-15

import sys

input = lambda: sys.stdin.readline().rstrip()

def fast_pow(a, p, mod):
    ret = 1

    while p:
        if p & 1:
            ret = ret * a % mod

        a = a * a % mod
        p >>= 1

    return ret


a, b, c = map(int, input().split())
print(fast_pow(a, b, c))
