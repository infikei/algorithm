# Solve 2023-03-07

import sys

a, b, c, d, p = map(int, sys.stdin.readlines())

ans = min(a * p, max(b, b + (p - c) * d))
print(ans)
