# Solve 2023-12-23

a = int(input())
b = int(input())
ans = b - a

if ans < 0:
    ans += 24

print(ans)
