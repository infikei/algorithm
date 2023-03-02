# Solve 2023-03-02

s = list(input() + ".")

check = True
tmp = 0
for i in range(len(s)):
    if s[i] == "X":
        tmp += 1
        if tmp == 4:
            tmp = 0
            s[i - 3] = s[i - 2] = s[i - 1] = s[i] = "A"
    else:
        if tmp == 2:
            s[i - 2] = s[i - 1] = "B"
            tmp = 0
        elif tmp != 0:
            check = False
            break

if check:
    print(*s[:-1], sep="")
else:
    print(-1)
