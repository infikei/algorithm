# Solve 2026-06-12

from itertools import product

d = ['0', '1', '4', '9']
p = product(d, d, d, d, d)
s = sorted(set(map(lambda x: int(''.join(x)), p)))

n = int(input())
print(s[n])
