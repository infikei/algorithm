# Solve 2022-05-28
# Update 2025-04-06

import sys
import collections

# 0. 입력을 받아서 저장한다.
n = int(sys.stdin.readline().rstrip())
nums = list(map(lambda x: int(x.rstrip()), sys.stdin.readlines()))

# 1. 산술평균을 출력한다.
print(round(sum(nums) / n))

# 2. 중앙값을 출력한다.
nums.sort()
print(nums[n // 2])

# 3. 최빈값을 출력한다.
counter = collections.Counter(nums).most_common()
mode_cnt = counter[0][1]
mode = list(filter(lambda x: x[1] == mode_cnt, counter))
mode = list(sorted(map(lambda x: x[0], mode)))

if len(mode) > 1:
    print(mode[1])
else:
    print(mode[0])

# 4. 범위를 출력한다.
print(nums[-1] - nums[0])
