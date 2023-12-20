# Solve 2023-10-09
# Update 2023-12-20

import sys
from collections import Counter

input = lambda : sys.stdin.readline().rstrip()

_ = input()
cnt = Counter(input().split())
_ = input()
queries = input().split()
answers = [str(cnt[query]) if query in cnt else "0" for query in queries]

print(" ".join(answers))
