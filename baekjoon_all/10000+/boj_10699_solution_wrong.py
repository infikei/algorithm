# Solve 2022-05-21
# Update 2023-12-19

# 아래의 풀이는 채점 서버(UTC+0)와 서울(UTC+9)의 시간대 차이를 고려하지 않은 풀이이다.
# 따라서 09:00 ~ 23:59에 제출할 경우, 채점 서버의 날짜와 서울의 날짜가 같으므로 정답 처리가 되며,
# 00:00 ~ 08:59에 제출할 경우, 채점 서버의 날짜와 서울의 날짜가 하루 차이가 나게 되므로 오답 처리가 된다.

# 따라서 현재 시간을 가져온 후 9시간을 더해주는 것이 올바른 풀이이며, 아래의 풀이는 올바르지 않은 풀이이다.

from datetime import date

today = date.today()
print(today)
