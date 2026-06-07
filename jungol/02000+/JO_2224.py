# Solve 2026-06-07

import sys

input = lambda: sys.stdin.readline().rstrip()

sentence = list(input())
sentence = [
    chr((ord(c) - ord('A') + 21) % 26 + ord('A')) if c.isupper() else c
    for c in sentence
]

print(''.join(sentence))
