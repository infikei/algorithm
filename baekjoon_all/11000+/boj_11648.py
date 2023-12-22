# Solve 2023-12-21
# Update 2023-12-22

from math import prod

n = input()
ans = 0

while len(n) > 1:
    n = str(prod(map(int, list(n))))
    ans += 1

print(ans)
