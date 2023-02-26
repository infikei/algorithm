# Solve 2022-05-30
# Update 2023-02-26

n = int(input())

for i in range(n):
    print(" " * i + "*" * ((n - i) * 2 - 1))

for i in range(n - 2, -1, -1):
    print(" " * i + "*" * ((n - i) * 2 - 1))
