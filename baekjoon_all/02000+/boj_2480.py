# Solve 2022-05-16
# Update 2023-02-22 #

a, b, c = map(int, input().split())

if a == b and b == c:
    ans = (a + 10) * 1000
elif a == b or a == c:
    ans = (a + 10) * 100
elif b == c:
    ans = (b + 10) * 100
else:
    ans = max([a, b, c]) * 100

print(ans)
