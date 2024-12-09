# Solve 2024-12-09

import sys
from decimal import *

getcontext().prec = 30
getcontext().rounding = ROUND_HALF_UP
input = lambda : sys.stdin.readline().rstrip()

a, b, c = map(Decimal, input().split())
print(a * b / c)
