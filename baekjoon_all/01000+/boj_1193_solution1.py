# Solve 2022-05-21
# Update 2023-03-02

x = int(input())

line = 1
tmp = 1
while tmp < x:
    line += 1
    tmp += line
tmp -= line

a = x - tmp
b = line + 1 - a
if line % 2 == 0:
    print(a, b, sep="/")
else:
    print(b, a, sep="/")
