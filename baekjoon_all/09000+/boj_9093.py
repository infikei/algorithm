# Solve 2023-03-23
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    sentence = input()
    reversed_words = map(lambda word: "".join(reversed(word)), sentence.split())
    print(" ".join(reversed_words))
