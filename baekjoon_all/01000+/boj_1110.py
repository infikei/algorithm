# Solve 2022-05-16
# Update 2023-02-26

cur = n = int(input())
ans = 0

while True:
    cur = cur % 10 * 10 + (cur // 10 + cur % 10) % 10
    ans += 1
    if cur == n:
        break

print(ans)
