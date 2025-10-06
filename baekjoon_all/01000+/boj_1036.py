# Solve 2025-10-05

import sys

input = lambda: sys.stdin.readline().rstrip()

def base_10_to_base_n(n: int, base: int) -> str:
    ret = ""

    while n:
        n, d = divmod(n, base)

        if d >= 10:
            ret += chr(ord("A") + (d - 10))
        else:
            ret += str(d)

    return ret[::-1] if ret else "0"


nums = [input() for _ in range(int(input()))]
k = int(input())
sum_by_digit = [0] * 36
plus_by_digit = [0] * 36

for num in nums:
    for i in range(len(num)):
        d = int(num[i], 36)
        p = pow(36, len(num) - 1 - i)
        sum_by_digit[d] += p
        plus_by_digit[d] += (35 - d) * p

li = []

for d in range(36):
    li.append([plus_by_digit[d], sum_by_digit[d], d])

li.sort(reverse=True)

for i in range(k):
    li[i][2] = 35

ans = sum(map(lambda x: x[1] * x[2], li))
ans = base_10_to_base_n(ans, 36)
print(ans)
