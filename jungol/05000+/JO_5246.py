# Solve 2026-06-07

a_school, a_grade = input().split()
a_grade = int(a_grade)
b_school, b_grade = input().split()
b_grade = int(b_grade)

print(a_school == b_school and a_grade != b_grade)
