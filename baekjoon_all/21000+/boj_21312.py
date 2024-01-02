# Solve 2024-01-01

from math import prod

li = list(map(int, input().split()))
even = [x for x in li if x % 2 == 0]
odd = [x for x in li if x % 2 == 1]

if len(odd) > 0:
    print(prod(odd))
else:
    print(prod(even))
