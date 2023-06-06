# Solve 2023-06-03

import sys
from decimal import *

getcontext().prec = 30
getcontext().rounding = ROUND_HALF_UP

input = lambda : sys.stdin.readline().rstrip()

def f(x, a, b, c, d):
    res = a * x * x * x + b * x * x + c * x + d
    return res

def bin_search(s, e, a, b, c, d):
    low, high = s, e
    max_err = Decimal("1.0e-12")

    while True:
        mid = (low + high) * Decimal("0.5")
        fmid = f(mid, a, b, c, d)

        if (high - low).copy_abs() < max_err:
            high = mid
            break
        elif fmid < Decimal("0"):
            low = mid
        elif fmid > Decimal("0"):
            high = mid
        else:
            high = mid
            break
    return high

for _ in range(int(input())):
    a, b, c, d = map(Decimal, input().split())
    if a < Decimal("0"):
        a, b, c, d = -a, -b, -c, -d

    discriminant = b * b - Decimal("3") * a * c
    ans = []

    if discriminant <= Decimal("0"):
        ans.append(bin_search(Decimal("-1000000"), Decimal("1000000"), a, b, c, d))
    else:
        x_lmax = (-b - discriminant ** Decimal("0.5")) / (Decimal("3") * a)
        x_lmin = (-b + discriminant ** Decimal("0.5")) / (Decimal("3") * a)

        y_lmax = round(f(x_lmax, a, b, c, d), 12)
        y_lmin = round(f(x_lmin, a, b, c, d), 12)

        if y_lmax == Decimal("0"):
            ans.append(x_lmax)
            ans.append(bin_search(x_lmin, Decimal("1000000"), a, b, c, d))
        elif y_lmin == Decimal("0"):
            ans.append(bin_search(Decimal("-1000000"), x_lmax, a, b, c, d))
            ans.append(x_lmin)
        elif y_lmax < Decimal("0"):
            ans.append(bin_search(x_lmin, Decimal("1000000"), a, b, c, d))
        elif y_lmin > Decimal("0"):
            ans.append(bin_search(Decimal("-1000000"), x_lmax, a, b, c, d))
        else:
            ans.append(bin_search(Decimal("-1000000"), x_lmax, a, b, c, d))
            ans.append(bin_search(x_lmax, x_lmin, -a, -b, -c, -d))
            ans.append(bin_search(x_lmin, Decimal("1000000"), a, b, c, d))

    for x in ans:
        print("{:.9f}".format(round(x, 9)), end=" ")
    print()
