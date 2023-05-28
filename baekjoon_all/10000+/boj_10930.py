# Solve 2023-05-27

import sys, hashlib

input = lambda : sys.stdin.readline().rstrip()

s = input()
ans = hashlib.sha256(s.encode()).hexdigest()
print(ans)
