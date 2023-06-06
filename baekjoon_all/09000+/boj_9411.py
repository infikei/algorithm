# Solve 2023-06-06

import sys
from decimal import *

getcontext().prec = 70
getcontext().rounding = ROUND_HALF_UP

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    ans = Decimal("0")

    while True:
        x = input()
        if x == "0":
            break
        ans += Decimal(x)

    ans = str(ans)
    while ans.find(".") != -1 and ans[-1] == "0":
        ans = ans[:-1]
    if ans[-1] == ".":
        ans = ans[:-1]
    print(ans)
