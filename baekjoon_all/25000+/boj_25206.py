# Solve 2023-02-26
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

sum_of_hakjum = sum_of_hakjum_grade = 0

for _ in range(20):
    subject_name, hakjum, grade_str = input().split()
    hakjum = float(hakjum)

    if grade_str == "P": continue

    grade = 0

    if grade_str != "F":
        if grade_str[0] == "A": grade = 4
        elif grade_str[0] == "B": grade = 3
        elif grade_str[0] == "C": grade = 2
        else: grade = 1

        if grade_str[1] == "+": grade += 0.5

    sum_of_hakjum += hakjum
    sum_of_hakjum_grade += hakjum * grade

print(sum_of_hakjum_grade / sum_of_hakjum)
