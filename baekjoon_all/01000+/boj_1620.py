# Solve 2023-10-09
# Update 2025-02-21

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
dogam_name = [""]
dogam_idx = {}

for i in range(1, n + 1):
    pokemon_name = input()
    dogam_name.append(pokemon_name)
    dogam_idx[pokemon_name] = i

for _ in range(m):
    query = input()

    if query[0] in "0123456789":
        print(dogam_name[int(query)])
    else:
        print(dogam_idx[query])
