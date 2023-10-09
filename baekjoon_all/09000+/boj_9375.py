# Solve 2023-10-09

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    clothes_type_cnt = dict()

    for _ in range(int(input())):
        clothes_name, clothes_type = input().split()

        if clothes_type in clothes_type_cnt:
            clothes_type_cnt[clothes_type] += 1
        else:
            clothes_type_cnt[clothes_type] = 1

    ans = 1

    for clothes_type in clothes_type_cnt:
        ans *= clothes_type_cnt[clothes_type] + 1

    print(ans - 1)
