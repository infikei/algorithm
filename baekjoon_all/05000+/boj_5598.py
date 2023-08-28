# Solve 2023-08-28

s = input()

for c in s:
    if ord(c) >= ord("D"):
        print(chr(ord(c) - 3), end="")
    else:
        print(chr(ord(c) + 23), end="")
