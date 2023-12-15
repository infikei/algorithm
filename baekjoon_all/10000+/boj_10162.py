# Solve 2023-12-15

t = int(input())

if t % 10 == 0:
    print(t // 300, t % 300 // 60, t % 60 // 10)
else:
    print(-1)
