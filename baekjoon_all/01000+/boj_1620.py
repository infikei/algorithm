# Solve 2023-10-09

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

    try:
        ans = dogam_name[int(query)]
    except ValueError:
        ans = dogam_idx[query]

    print(ans)
