n, x = map(int, input().split())
a = list(map(int, input().split()))
ans = []

for i in a:
    if i < x:
        ans.append(i)
print(*ans)
