# Solve 2023-03-20

a, b = map(lambda x: int(x, 2), input().split())

print(bin(a + b)[2:])
