# Solve 2023-12-23

n = input()
ans = 0

if "7" in n:
    ans += 2

if int(n) % 7 == 0:
    ans += 1

print(ans)
