# Solve 2023-12-21

from collections import Counter

cnt = Counter(input().split())

print(1 if cnt["1"] > cnt["2"] else 2)
