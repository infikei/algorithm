# Solve 2022-05-21
# Update 2023-02-08

n = int(input())
ans, val = 1, 1
while n > val:
    val += ans * 6
    ans += 1

print(ans)
