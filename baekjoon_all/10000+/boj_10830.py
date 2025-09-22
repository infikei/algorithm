# Solve 2025-09-16
# Update 2025-09-22

import sys

input = lambda: sys.stdin.readline().rstrip()

def mat_mul(a: list[list[int]], b: list[list[int]]) -> list[list[int]]:
    ret = [[0] * len(b[0]) for _ in range(len(a))]

    for i in range(len(a)):
        for j in range(len(b[0])):
            for k in range(len(b)):
                ret[i][j] += a[i][k] * b[k][j]

            ret[i][j] %= 1000

    return ret


def mat_pow(a: list[list[int]], p: int) -> list[list[int]]:
    ret = [[0] * len(a) for _ in range(len(a))]

    for i in range(len(a)):
        ret[i][i] = 1

    while p:
        if p & 1:
            ret = mat_mul(ret, a)

        a = mat_mul(a, a)
        p >>= 1

    return ret


n, b = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(n)]
result = mat_pow(mat, b)

for row in result:
    print(*row)
