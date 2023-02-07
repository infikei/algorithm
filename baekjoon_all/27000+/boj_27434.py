# Solve 2023-02-08

n = int(input())

ans = 1
for i in range(2, n + 1):
    ans *= i
print(ans)