# Solve 2023-03-03

abc1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
abc2 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"

s = input()

ans = ""
for i in range(len(s)):
    idx = abc1.find(s[i])
    if idx != -1:
        ans += abc2[idx]
    else:
        ans += s[i]

print(ans)
