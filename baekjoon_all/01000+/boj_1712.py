# Solve 2022-05-21
# Update 2024-05-14

a, b, c = map(int, input().split())

if b >= c:
    print(-1)
else:
    print(int(a / (c - b)) // 1 + 1)
