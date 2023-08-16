# Solve 2022-05-28
# Update 2023-08-16

import sys

input = lambda : sys.stdin.readline().rstrip()

month_days = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

x, y = map(int, input().split())

today = month_days[x - 1] + y

print(days[today % 7])
