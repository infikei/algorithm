# Solve 2022-05-29
# Update 2023-09-09

s = input()
w = []

for c in s:
    w.append(c)

    if len(w) == 10:
        print(*w, sep="")
        w.clear()

if len(w) > 0:
    print(*w, sep="")
