# Solve 2026-06-15

import sys

input = lambda: sys.stdin.readline().rstrip()

def get_sqrt(x):
    ret = 0

    while (ret + 1) ** 2 <= x:
        ret += 1

    return ret


n, k = map(int, input().split())
divisors = []

for i in range(1, get_sqrt(n) + 1):
    if n % i == 0:
        divisors.append(i)

        if i * i != n:
            divisors.append(n // i)

divisors.sort()
print(divisors[k - 1] if k <= len(divisors) else 0)
