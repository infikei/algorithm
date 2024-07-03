# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

s = input()

s = s.replace("(", " ( ").replace(")", " ) ")
s = s.replace("<", " < ").replace(">", " > ")
s = s.replace("&&", " && ").replace("||", " || ")
s = list(filter(lambda x: x, s.split(" ")))
print(*s, sep=" ")
