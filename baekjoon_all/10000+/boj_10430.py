# Solve 2022-05-15
# Update 2023-02-26

a, b, c = map(int, input().split())

print((a + b) % c)
print((a % c + b % c) % c)
print(a * b % c)
print((a % c) * (b % c) % c)
