# Solve 2022-05-29
# Update 2023-02-26

n = int(input())

for i in range(1, n + 1):
    print(" " * (n - i) + "*" * (2 * i - 1))
