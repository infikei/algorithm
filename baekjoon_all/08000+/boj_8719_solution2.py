# Solve 2023-12-10

# Python 3 제출 : 통과
# PyPy3 제출 : 통과

import sys

t = int(sys.stdin.readline().rstrip())
li = map(lambda x: map(int, x.rstrip().split()), sys.stdin.readlines())

for x, w in li:
    ans = 0

    while x < w:
        x <<= 1
        ans += 1

    print(ans)
