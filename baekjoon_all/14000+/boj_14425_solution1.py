# Solve 2023-10-09

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
string_set = {input() for _ in range(n)}
ans = 0

for _ in range(m):
    query = input()

    if query in string_set:
        ans += 1

print(ans)
