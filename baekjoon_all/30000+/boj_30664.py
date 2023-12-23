# Solve 2023-12-23

import sys

input = lambda : sys.stdin.readline().rstrip()

while (n := int(input())) != 0:
    print("PREMIADO" if n % 42 == 0 else "TENTE NOVAMENTE")
