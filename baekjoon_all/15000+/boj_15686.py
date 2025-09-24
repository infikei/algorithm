# Solve 2025-09-23

import sys
from itertools import combinations

input = lambda: sys.stdin.readline().rstrip()

def get_dist(p1: tuple[int], p2: tuple[int]) -> int:
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
houses = []
chickens = []

for x in range(n):
    for y in range(n):
        if board[x][y] == 1:
            houses.append((x, y))
        elif board[x][y] == 2:
            chickens.append((x, y))

dist = [[0] * len(houses) for _ in range(len(chickens))]

for i in range(len(chickens)):
    for j in range(len(houses)):
        dist[i][j] = get_dist(chickens[i], houses[j])

min_city_chicken_dist = float("inf")

for selected_c_indices in combinations(range(len(chickens)), m):
    city_chicken_dist = 0

    for h_idx in range(len(houses)):
        chicken_dist = min(map(lambda c_idx: dist[c_idx][h_idx], selected_c_indices))
        city_chicken_dist += chicken_dist

    min_city_chicken_dist = min(min_city_chicken_dist, city_chicken_dist)

print(min_city_chicken_dist)
