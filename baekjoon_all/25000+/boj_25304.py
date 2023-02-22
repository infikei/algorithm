# Solve 2023-02-22

x, x2 = int(input()), 0
n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    x2 += a * b

if x == x2:
    print("Yes")
else:
    print("No")
