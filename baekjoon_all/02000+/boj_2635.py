# Solve 2023-03-03

n = int(input())

ans = []
for k in range(1, n + 1):
    now = [n, k]
    while True:
        tmp = now[-2] - now[-1]
        if tmp < 0:
            break
        now.append(tmp)

    if len(now) > len(ans):
        ans = now

print(len(ans))
print(*ans, sep=" ")
