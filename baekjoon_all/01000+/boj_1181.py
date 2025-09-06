# Solve 2022-05-30
# Update 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

words = list(set(input() for _ in range(int(input()))))
words.sort(key=lambda x: (len(x), x))
print("\n".join(words))
