n = int(input())
li = [[] for _ in range(200)]  # li : list of list

for i in range(n):
    a, b = input().split()
    a = int(a)
    li[a-1].append((a, b))

for i in li:  # i : list of tuple, li : list of list of tuple
    if len(i) > 0:
        for j in i:  # j : tuple
            print(*j)
