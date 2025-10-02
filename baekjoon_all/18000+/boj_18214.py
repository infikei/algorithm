# Solve 2025-10-02

import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()

MOD = 1000000007

def solution(n: int, m: int, nums: list[int]) -> int:
    max_v = 0
    last = [0, 0]
    cnt = [0, 0]
    counter = {0: 1}

    for i in range(1, n + 1):
        max_v = max(max_v, nums[i])

        if last[0] < nums[i]:
            last[0] = nums[i]
            cnt[0] += 1
        elif last[1] < nums[i]:
            last[1] = nums[i]
            cnt[1] += 1
        else:
            return 0

        if max_v == i:
            new_counter = {}

            for k, v in counter.items():
                new_counter[k + cnt[0]] = new_counter.get(k + cnt[0], 0) + v
                new_counter[k + cnt[1]] = new_counter.get(k + cnt[1], 0) + v

            counter = new_counter
            cnt = [0, 0]

    ans = sum([v if k >= n - m and k <= m else 0 for k, v in counter.items()])
    return ans % MOD


n, m = map(int, input().split())
nums = list(map(int, ("0 " + input()).split()))
print(solution(n, m, nums))
