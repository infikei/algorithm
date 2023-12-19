# Solve 2023-02-26
# Update 2023-12-19

s = input()
cnt = [0] * 26

for c in s:
    cnt[ord(c) - ord("a")] += 1

print(*cnt)
