# Solve 2022-05-21
# Update 2023-02-08

n = int(input())
ans = 1
while n > 3 * ans * (ans - 1) + 1:
    ans += 1

print(ans)
