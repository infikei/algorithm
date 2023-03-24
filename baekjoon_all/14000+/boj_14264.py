# Solve 2023-03-23

import sys
from math import pi, sin

input = lambda : sys.stdin.readline().rstrip()

l = int(input())

ans = l * l * sin(pi / 3) * 0.5
print("%.12f" % ans)
