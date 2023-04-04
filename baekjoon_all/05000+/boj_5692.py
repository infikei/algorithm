# Solve 2023-04-03

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    n = int(input())
    if n == 0:
        break

    i = 1
    fac = 1
    ans = 0
    while n > 0:
        fac *= i
        ans += (n % 10) * fac
        n //= 10
        i += 1
    print(ans)
