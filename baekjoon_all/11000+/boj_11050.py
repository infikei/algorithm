# Solve 2022-05-22
# Update 2023-09-02

n, k = map(int, input().split())
ans = 1

if k > n // 2:
    k = n - k

for i in range(k):
    ans *= n - i
    ans //= i + 1

print(ans)
