# Solve 2023-02-26

import sys

li = list(sorted(map(lambda x: int(x.rstrip()), sys.stdin.readlines())))

print(sum(li) // 5, li[2], sep="\n")
