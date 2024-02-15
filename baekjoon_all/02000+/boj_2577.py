# Solve 2022-05-19
# Update 2024-02-15

abc = int(input()) * int(input()) * int(input())

digits = []

while abc > 0:
    digits.append(abc % 10)
    abc //= 10

for d in range(10):
    print(digits.count(d))
