# Solve 2023-03-16

import sys
from math import floor, sqrt

input = lambda : sys.stdin.readline().rstrip()

d, h_ratio, w_ratio = map(int, input().split())

d_ratio = sqrt(h_ratio ** 2 + w_ratio ** 2)
h = floor(d * h_ratio / d_ratio)
w = floor(d * w_ratio / d_ratio)

print(h, w)
