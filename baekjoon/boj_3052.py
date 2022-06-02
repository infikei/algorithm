lst = []
ans = 0
for i in range(10):
    n = int(input()) % 42
    if n not in lst:
        ans += 1
        lst.append(n)
print(ans)
