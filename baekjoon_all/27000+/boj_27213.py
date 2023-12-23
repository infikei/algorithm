# Solve 2023-12-23

m = int(input())
n = int(input())

if m == 1:
    print(n)
elif n == 1:
    print(m)
else:
    print((m + n) * 2 - 4)
