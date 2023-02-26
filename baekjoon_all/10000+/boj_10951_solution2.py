# Solve 2022-05-16
# Update 2023-02-26

# Solution 2.

import sys

for line in sys.stdin.readlines():
    print(sum(map(int, line.split())))
