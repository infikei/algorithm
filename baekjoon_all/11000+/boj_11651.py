n = int(input())
li = [0] * n
for i in range(n):
    x, y = map(int, input().split())
    li[i] = (y, x)

for i in sorted(li):
    print(i[1], i[0])
