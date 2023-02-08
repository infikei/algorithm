# Solve 2022-05-21
# Update 2023-02-08

from math import ceil, sqrt

n = int(input())
tmp = ceil((n - 1) / 6)
ans = ceil((sqrt(tmp * 8 + 1) - 1) / 2) + 1

print(ans)
