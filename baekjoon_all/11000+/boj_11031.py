# Solve 2025-12-02

import sys

input = lambda: sys.stdin.readline().rstrip()

while line := input():
    n = int(line)
    memo = [1]
    o, a1, a2 = 1, 0, 0

    for i in range(1, n + 1):
        o, a1, a2 = o + a1 + a2, o, a1
        memo.append(o + a1 + a2)

    ans = memo[n]

    for i in range(n):
        j = n - 1 - i
        ans += memo[i] * memo[j]

    print(ans)
