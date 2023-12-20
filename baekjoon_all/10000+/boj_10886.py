# Solve 2023-03-04
# Update 2023-12-20

import sys
from collections import Counter

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
cnt = Counter([int(input()) for _ in range(n)])

print("Junhee is not cute!" if cnt[0] > cnt[1] else "Junhee is cute!")
