# Solve 2025-10-30

import sys
from math import comb

input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
c = comb(n, k)
print(str(c).count("0"))
