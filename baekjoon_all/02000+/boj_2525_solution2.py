# Solve 2022-05-16
# Update 2023-02-22 #

hour, minute = map(int, input().split())
extra = int(input())

minute += extra
while minute >= 60:
    minute -= 60
    hour += 1
while hour >= 24:
    hour -= 24

print(hour, minute)
