k = int(input())
li = []

for i in range(k):
    x = int(input())
    if x == 0:
        li.pop()
    else:
        li.append(x)

print(sum(li))
