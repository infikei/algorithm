# Solve 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

def calc(a, op, b):
    if op == "+":
        return a + b
    if op == "-":
        return a - b
    if op == "*":
        return a * b
    if op == "/":
        sign = 1

        if a < 0:
            sign = -sign
            a = -a

        if b < 0:
            sign = -sign
            b = -b

        return a // b * sign

    return 1

n1, op1, n2, op2, n3 = input().split()
n1 = int(n1)
n2 = int(n2)
n3 = int(n3)

ans1 = calc(calc(n1, op1, n2), op2, n3)
ans2 = calc(n1, op1, calc(n2, op2, n3))
print(min(ans1, ans2), max(ans1, ans2), sep="\n")
