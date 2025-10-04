# Solve 2025-10-02
# Update 2025-10-04

import sys

input = lambda: sys.stdin.readline().rstrip()

MOD = 1000000007

def solution(n: int, m: int, nums: list[int]) -> int:
    max_v = 0
    last = [0, 0]
    cnt = [0, 0]
    memo = [0] * (n + 1)
    memo[0] = 1

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
            for v in range(max_v, -1, -1):
                m0 = memo[v - cnt[0]] if v >= cnt[0] else 0
                m1 = memo[v - cnt[1]] if v >= cnt[1] else 0
                memo[v] = m0 + m1

            cnt = [0, 0]

    return sum(memo[n - m : m + 1]) % MOD


n, m = map(int, input().split())
nums = list(map(int, ("0 " + input()).split()))
print(solution(n, m, nums))
