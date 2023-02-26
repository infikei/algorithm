# Solve 2022-05-19
# Update 2023-02-26

n = int(input())
s = int(input())
ans = 0

while s > 0:
    ans += s % 10
    s //= 10

print(ans)
