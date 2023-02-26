# Solve 2022-05-20
# Update 2023-02-26

word = input()
ans = 0

for ch in word:
    tmp = ord(ch) - 65
    if tmp >= 18:
        tmp -= 1
    if tmp >= 24:
        tmp -= 1
    ans += tmp // 3 + 3

print(ans)
