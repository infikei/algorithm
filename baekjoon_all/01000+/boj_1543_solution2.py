# Solve 2023-10-22
# Update 2025-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

document = input()
word = input()

print(len(document.split(word)) - 1)
