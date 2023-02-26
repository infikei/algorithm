# Solve 2023-02-26

word = input()
ans = 1
i, j = 0, len(word) - 1

while i < j:
    if word[i] != word[j]:
        ans = 0
        break
    i += 1
    j -= 1

print(ans)
