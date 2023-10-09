# Solve 2023-10-08

st = set(input())
targets = {"I", "O", "S", "H", "Z", "X", "N"}

if len(st - targets) == 0:
    print("YES")
else:
    print("NO")
