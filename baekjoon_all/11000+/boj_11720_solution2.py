# Solve 2022-05-19
# Update 2023-02-26

n = int(input())
s = input()
ans = 0

for i in range(n):
    ans += int(s[i])

print(ans)
