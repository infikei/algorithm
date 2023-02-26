# Solve 2023-02-26

s = input()
cnt = [0] * 26
for ch in s:
    cnt[ord(ch) - 97] += 1 # 97 = ord("a")

print(*cnt)
