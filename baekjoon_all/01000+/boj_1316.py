# Solve 2022-05-20
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
ans = 0

for _ in range(n):
    word = input()
    li = list(set(word))
    group_word = True

    for ch in li:
        idx = word.find(ch)
        cnt = word.count(ch)
        for i in range(cnt):
            if word[idx + i] != ch:
                group_word = False
                break
        if not group_word:
            break
    if group_word:
        ans += 1

print(ans)
