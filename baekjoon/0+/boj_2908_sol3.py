a, b = input().split()
a = ''.join(reversed(a))
b = ''.join(reversed(b))
if a > b:
    print(a)
else:
    print(b)