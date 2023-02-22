# Solve 2022-05-15
# Update 2023-02-22

a = int(input())
b = int(input())
print(a * (b % 10))
print(a * (b // 10 % 10))
print(a * (b // 100))
print(a * b)
