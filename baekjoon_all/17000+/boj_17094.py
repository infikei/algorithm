# Solve 2023-12-21

import sys
from collections import Counter

input = lambda : sys.stdin.readline().rstrip()

_ = input()
s = input()
cnt = Counter(s)

if cnt["2"] > cnt["e"]:
    print("2")
elif cnt["2"] < cnt["e"]:
    print("e")
else:
    print("yee")
