# Solve 2023-03-14

import sys
from collections import Counter

input = lambda : sys.stdin.readline().rstrip()

v = int(input())
votes = input()
cnt = Counter(votes).most_common()

if len(cnt) > 1 and cnt[0][1] == cnt[1][1]:
    print("Tie")
else:
    print(cnt[0][0])
