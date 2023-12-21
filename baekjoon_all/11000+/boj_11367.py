# Solve 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    name, grade = input().split()
    grade = int(grade)

    if grade >= 97:
        print(name, "A+")
    elif grade >= 90:
        print(name, "A")
    elif grade >= 87:
        print(name, "B+")
    elif grade >= 80:
        print(name, "B")
    elif grade >= 77:
        print(name, "C+")
    elif grade >= 70:
        print(name, "C")
    elif grade >= 67:
        print(name, "D+")
    elif grade >= 60:
        print(name, "D")
    else:
        print(name, "F")
