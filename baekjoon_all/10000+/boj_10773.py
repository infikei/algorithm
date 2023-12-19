# Solve 2022-05-30
# Update 2023-12-19

li = []

for _ in range(int(input())):
    x = int(input())

    if x == 0:
        li.pop()
    else:
        li.append(x)

print(sum(li))
