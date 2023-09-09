# Solve 2022-05-30
# Update 2023-09-09

import sys

lines = sys.stdin.readlines()

for line in lines:
    if line[-1] == "\n":
        print(line[:-1])
    else:
        print(line)
