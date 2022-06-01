y = int(input())

if y % 400 == 0:
    print(1)
elif y % 100 == 0:
    print(0)
elif y % 4 == 0:
    print(1)
else:
    print(0)
