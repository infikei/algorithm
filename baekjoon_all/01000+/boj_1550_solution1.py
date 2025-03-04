# Solve 2022-05-25
# Update 2024-02-21

s = input()
n = 0

for ch in s:
    n *= 16

    if ch == "A":
        n += 10
    elif ch == "B":
        n += 11
    elif ch == "C":
        n += 12
    elif ch == "D":
        n += 13
    elif ch == "E":
        n += 14
    elif ch == "F":
        n += 15
    else:
        n += int(ch)

print(n)
