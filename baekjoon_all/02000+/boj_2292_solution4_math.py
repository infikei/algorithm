# Solve 2022-05-21
# Update 2023-02-26

# 풀이 과정은 boj_27436.cpp 파일의 주석을 참고할 것.

import math

n = int(input())

ans = round(math.sqrt((n * 4 - 1) / 12) - 1)
ans = max(ans, 1)
while n > ans * (ans - 1) * 3 + 1:
    ans += 1

print(ans)
