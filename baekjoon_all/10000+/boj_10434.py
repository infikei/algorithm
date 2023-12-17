# Solve 2023-12-16

import sys
from math import sqrt

def is_prime(n):
    if n == 1:
        return False

    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return False

    return True

def is_happy(n):
    if n == 1:
        return True

    visited = [False for _ in range(10001)]
    visited[n] = True

    while True:
        n = sum(map(lambda d: int(d) ** 2, str(n)))

        if n == 1:
            return True
        if visited[n]:
            return False

        visited[n] = True

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    ti, n = map(int, input().split())

    if is_prime(n) and is_happy(n):
        print(ti, n, "YES")
    else:
        print(ti, n, "NO")
