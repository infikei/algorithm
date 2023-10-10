# Solve 2023-03-01
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n, k = map(int, input().split())
teams = []
target_team = (0, 0, 0)

for _ in range(n):
    team_idx, gold, silver, bronze = map(int, input().split())

    teams.append((gold, silver, bronze))

    if team_idx == k:
        target_team = (gold, silver, bronze)

teams.sort(reverse=True)

print(teams.index(target_team) + 1)
