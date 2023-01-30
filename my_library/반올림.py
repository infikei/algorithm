def round(n):
    a = int(n//1)
    b = int((n*10)//1) % 10
    if b >= 5:
        return a+1
    else:
        return a


# Test
while True:
    i = float(input())
    print(round(i))
