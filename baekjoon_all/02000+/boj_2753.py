# Solve 2022-05-16
# Update 2023-02-22 #

year = int(input())

if year % 400 == 0:
    print(1)
elif year % 100 == 0:
    print(0)
elif year % 4 == 0:
    print(1)
else:
    print(0)
