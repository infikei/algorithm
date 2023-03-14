# Solve 2022-05-29
# Update 2023-03-14

import sys

input = lambda : sys.stdin.readline().rstrip()

p = [list(map(int, input().split())) for _ in range(3)]
p.append([0, 0])

for j in range(2):
    if p[0][j] == p[1][j]:
        p[3][j] = p[2][j]
    elif p[0][j] == p[2][j]:
        p[3][j] = p[1][j]
    else:
        p[3][j] = p[0][j]

print(*p[3])
