# Solve 2022-05-19
# Update 2023-10-10

s = input()
ans = [-1] * 26

for i in range(0, 26):
    ch = chr(i + 97)
    ans[i] = s.find(ch)

print(*ans)
