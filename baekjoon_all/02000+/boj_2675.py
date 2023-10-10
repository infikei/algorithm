# Solve 2022-05-19
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    repeat, word = input().split()
    repeat = int(repeat)
    ans = ""

    for ch in word:
        ans += ch * repeat

    print(ans)
