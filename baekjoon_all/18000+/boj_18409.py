# Solve 2023-12-21

import sys
from collections import Counter

input = lambda : sys.stdin.readline().rstrip()

_ = input()
s = input()
cnt = Counter(s)
aeiou = list("aeiou")

print(sum([cnt[a] for a in aeiou]))
