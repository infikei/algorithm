# Solve 2023-06-04

import sys
from decimal import *

getcontext().prec = 1000
getcontext().rounding = ROUND_HALF_UP

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = Decimal(input())

    low, high = Decimal("1"), n
    max_err = Decimal("1.0e-100")

    while True:
        mid = (low + high) * Decimal("0.5")
        val = mid ** Decimal("3")

        if (high - low).copy_abs() < max_err:
            low = mid
            break
        elif val < n:
            low = mid
        elif val > n:
            high = mid
        else:
            low = mid
            break

    low = low.quantize(Decimal("1.0e-500"), rounding=ROUND_HALF_UP)
    low = low.quantize(Decimal(".0000000001"), rounding=ROUND_DOWN)
    print(low)
