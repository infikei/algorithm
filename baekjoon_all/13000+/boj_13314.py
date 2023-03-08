# Solve 2023-03-07

n = 100
print(n)

ans = ""

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            ans += "0 "
        elif i == n or j == n:
            ans += "1 "
        else:
            ans += "3 "
    ans += "\n"

print(ans)
