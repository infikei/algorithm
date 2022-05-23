i = n = int(input())
ans = 0

while True:
    i = i % 10*10+(i//10+i % 10) % 10
    ans += 1
    if i == n:
        break
print(ans)
