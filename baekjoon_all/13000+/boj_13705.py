# Solve 2023-03-18

import sys
from decimal import *

getcontext().prec = 30
getcontext().rounding = ROUND_HALF_UP

input = lambda : sys.stdin.readline().rstrip()

def new_sin(x):
    x = Decimal(x) % (Decimal("2") * pi)

    res = x
    x2, xk = -x * x, x
    fac, i = Decimal("1"), Decimal("0")
    while True:
        res_old = res
        xk *= x2
        i += Decimal("2")
        fac *= i * i + i
        res += xk / fac
        if res == res_old:
            break
    return res

def f(x):
    x = Decimal(x)
    return a * x + b * new_sin(x) - c

pi = Decimal("3.14159265358979323846264338327950288419716939937510")

a, b, c = map(Decimal, input().split())

low, high = (c - b) / a, (c + b) / a
max_err = Decimal("1.0e-24")
while True:
    mid = (low + high) / Decimal("2")
    fmid = f(mid)
    if (high - low).copy_abs() < max_err:
        high = mid
        break
    if fmid < Decimal("0"):
        low = mid
    elif fmid > Decimal("0"):
        high = mid
    else:
        high = mid
        break

print(round(high, 6))
