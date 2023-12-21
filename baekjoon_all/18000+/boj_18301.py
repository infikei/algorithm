# Solve 2022-06-02
# Update 2023-12-21

n1, n2, n12 = map(int, input().split())
n = (n1 + 1) * (n2 + 1) // (n12 + 1) - 1
print(n)
