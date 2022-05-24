x = input()
n = len(x)
ans = 0

for i in x:
    n -= 1
    if i == "A":
        ans += 10*16**n
    elif i == "B":
        ans += 11*16**n
    elif i == "C":
        ans += 12*16**n
    elif i == "D":
        ans += 13*16**n
    elif i == "E":
        ans += 14*16**n
    elif i == "F":
        ans += 15*16**n
    else:
        ans += int(i)*16**n

print(ans)
