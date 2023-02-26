# Solve 2022-05-30
# Update 2023-02-26

n = int(input())

for i in range(1, n + 1):
    print("*" * i + " " * ((n - i) * 2) + "*" * i)

for i in range(n - 1, 0, -1):
    print("*" * i + " " * ((n - i) * 2) + "*" * i)
