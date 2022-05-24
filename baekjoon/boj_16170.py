import datetime

# 지금 시각을 받아온다. (이때 받아오는 시각은 한국시간 기준 UTC+9)
d = datetime.datetime.now()
# UTC-0 기준의 시각을 계산하기 위해 -9시간을 더한다.
d += datetime.timedelta(hours=-9)

print(d.year)
print(d.month)
print(d.day)
