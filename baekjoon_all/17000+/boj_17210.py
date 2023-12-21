# Solve 2023-12-21

n = int(input())
x = int(input())

if n >= 6:
    print("Love is open door")
else:
    for _ in range(2, n + 1):
        x = 1 - x
        print(x)
