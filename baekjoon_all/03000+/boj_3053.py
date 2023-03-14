# Solve 2022-05-29
# Update 2023-03-14

import sys
from math import pi

input = lambda : sys.stdin.readline().rstrip()

r = int(input()) ** 2

print("%.6f" % (r * pi))
print("%.6f" % (r * 2))
