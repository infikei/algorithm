month, day = map(int, input().split())

month_li = [0, 1, -1, 0, 0, 1, 1, 2, 3, 3, 4, 4]
day_li = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']

day += 30*(month-1)+month_li[month-1]
print(day_li[day % 7])

# 입력된 month 값의 이전 달까지의 일 값을 day에 더해준다.
# month = 3 이면 day에 30*2 = 60을 더해주고 month_li에 미리 저장된 그 보정치도 함께 더해준다.
