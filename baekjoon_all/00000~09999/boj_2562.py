max = 0
find = 0
for i in range(9):
    n = int(input())
    if n > max:
        max = n
        find = i
print(max)
print(find+1)
