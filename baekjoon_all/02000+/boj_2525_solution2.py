# Solve 2022-05-16
# Update 2023-10-09

hour, minute = map(int, input().split())
extra = int(input())

minute += extra

if minute >= 60:
    hour += minute // 60
    minute %= 60

if hour >= 24:
    hour %= 24

print(hour, minute)
