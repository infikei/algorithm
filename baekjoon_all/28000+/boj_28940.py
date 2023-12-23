# Solve 2023-12-23

w, h = map(int, input().split())
n, a, b = map(int, input().split())

p = (w // a) * (h // b)
ans = -1

if p > 0:
    ans = (n - 1) // p + 1

print(ans)
