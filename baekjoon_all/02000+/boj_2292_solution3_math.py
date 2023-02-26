# Solve 2022-05-21
# Update 2023-02-26

import math

n = int(input())
tmp = math.ceil((n - 1) / 6)
ans = math.ceil((math.sqrt(tmp * 8 + 1) - 1) / 2) + 1

print(ans)
