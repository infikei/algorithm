# Solve 2022-05-16
# Update 2023-02-26

hour, minute = map(int, input().split())

if minute >= 45:
    minute -= 45
else:
    minute += 15
    if hour == 0:
        hour = 23
    else:
        hour -= 1

print(hour, minute)
