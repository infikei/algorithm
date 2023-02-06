n = int(input())
li = [0] * n

for i in range(n):
    li[i] = tuple(map(int, input().split()))

for i in sorted(li):
    print(*i)
