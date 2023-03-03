# Solve 2023-03-03

t10 = int(input())
t9 = ""
while t10 > 0:
    t9 = str(t10 % 9) + t9
    t10 //= 9

print(t9)
