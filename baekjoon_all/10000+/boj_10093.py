# Solve 2023-03-14
# Update 2023-12-15

a, b = sorted(map(int, input().split()))

if b - a <= 1:
    print(0)
else:
    print(b - a - 1)
    print(*range(a + 1, b))
