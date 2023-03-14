# Solve 2023-03-14

import sys

input = lambda : sys.stdin.readline().rstrip()

angles = [int(input()) for _ in range(3)]

if sum(angles) != 180:
    print("Error")
elif angles[0] == 60 and angles[1] == 60:
    print("Equilateral")
elif angles[0] == angles[1] or angles[1] == angles[2] or angles[2] == angles[0]:
    print("Isosceles")
else:
    print("Scalene")
