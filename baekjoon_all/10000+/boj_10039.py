# Solve 2022-05-26
# Update 2023-03-14

import sys

input = lambda : sys.stdin.readline().rstrip()

scores = [max(40, int(input())) for _ in range(5)]
ans = sum(scores) // 5
print(ans)
