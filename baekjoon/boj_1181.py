n = int(input())
li = [[] for _ in range(50)]

for i in range(n):
    st = input()
    if st not in li[len(st)-1]:
        li[len(st)-1].append(st)

for i in li:
    if len(i) != 0:
        for j in sorted(i):
            print(j)
