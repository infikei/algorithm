# Solve 2023-06-06
# Update 2023-12-13

import sys
from decimal import *

getcontext().prec = 70
getcontext().rounding = ROUND_HALF_UP

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    ans = Decimal("0")

    while (x := input()) != "0":
        ans += Decimal(x)

    ans = str(ans)

    while ans.find(".") != -1 and ans[-1] == "0":
        ans = ans[:-1]

    if ans[-1] == ".":
        ans = ans[:-1]

    print(ans)
