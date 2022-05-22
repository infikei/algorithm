# solution 2.

import sys

for line in sys.stdin.readlines():
    print(sum(map(int, line.split())))
