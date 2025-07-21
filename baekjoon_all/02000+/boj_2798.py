# Solve 2022-05-26
# Update 2025-07-20

import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
nums = list(map(int, input().split()))
ans = 0

for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            s3 = nums[i] + nums[j] + nums[k]

            if s3 <= m:
                ans = max(ans, s3)

print(ans)
