# Solve 2023-03-20

import sys

input = lambda : sys.stdin.readline().rstrip()

word = input()
ans = "z" * len(word)

for i in range(1, len(word)):
    for j in range(i + 1, len(word)):
        new_word = list(reversed(word[:i])) + list(reversed(word[i:j])) + list(reversed(word[j:]))
        new_word = "".join(new_word)
        if new_word < ans:
            ans = new_word

print(ans)
