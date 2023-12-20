# Solve 2022-05-25
# Update 2023-12-20

n = int(input())
ans = 1

for i in range(2, n + 1):
    ans *= i

print(ans)
