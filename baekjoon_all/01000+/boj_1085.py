# Solve 2022-05-29
# Update 2023-03-13

x, y, w, h = map(int, input().split())

print(min(x, y, w - x, h - y))
