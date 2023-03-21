# Solve 2023-03-20

word = input()
word_rev = "".join(list(reversed(word)))
max_same_len = 0

for now_len in range(1, len(word) + 1):
    if word[-now_len:] == word_rev[:now_len]:
        max_same_len = now_len

print(len(word) * 2 - max_same_len)
