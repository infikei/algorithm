# solution 1. 그냥코딩

a = int(input())
i = 1
while True:
    if a <= 3 * i * (i-1) + 1:
        print(i)
        break
    i += 1
