# Solve 2022-05-21
# Update 2023-03-02

from math import ceil, sqrt

x = int(input())
y = ceil((sqrt(8 * x + 1) - 1) / 2)
a = int(x - y * (y - 1) / 2)
b = int(y + 1 - a)

if y % 2 == 0:
    print(a, b, sep="/")
else:
    print(b, a, sep="/")
