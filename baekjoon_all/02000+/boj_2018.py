# Solve 2023-03-02

n = int(input())

ans = 0
i = 1
j = 2
now = 1

while i <= n:
    if now < n:
        now += j
        j += 1
    elif now > n:
        now -= i
        i += 1
    else:
        ans += 1
        now -= i
        i += 1
        now += j
        j += 1

print(ans)
