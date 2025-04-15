# Solve 2022-05-30
# Update 2025-04-15

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = [[] for _ in range(51)]

for i in range(n):
    word = input()

    if word not in li[len(word)]:
        li[len(word)].append(word)

for words in li:
    if len(words) != 0:
        for word in sorted(words):
            print(word)
