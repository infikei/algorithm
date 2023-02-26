# Solve 2022-05-28
# Update 2023-02-26

import sys
import collections

# 입력값 저장하기
n = int(sys.stdin.readline().rstrip())
nums = list(map(lambda x: int(x.rstrip()), sys.stdin.readlines()))

# ans1 : 산술평균 구하기
ans1_avr = round(sum(nums) / n)

# ans2 : 중앙값 구하기
# ans4 : 범위 구하기
nums.sort()
ans2_center = nums[n // 2]
ans4_range = nums[-1] - nums[0]

# ans3 : 최빈값 구하기
counter = collections.Counter(nums).most_common()
most_cnt = counter[0][1]
ans3_most_vals = list(filter(lambda x: x[1] == most_cnt, counter))
ans3_most_vals = list(sorted(map(lambda x: x[0], ans3_most_vals)))

# 결과 출력하기
print(ans1_avr)
print(ans2_center)
if len(ans3_most_vals) > 1:
    print(ans3_most_vals[1])
else:
    print(ans3_most_vals[0])
print(ans4_range)
