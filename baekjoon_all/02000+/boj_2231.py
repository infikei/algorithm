# Solve 2022-05-25
# Update 2023-03-13

n = int(input())
ans = 0

for k in range(1, n):
    res = k
    for i in str(k):
        res += int(i)
    if res == n:
        ans = k
        break

print(ans)
