N = int(input())
if N < 100:
    print(N)
else:
    ans = 99
    for i in range(100, N+1):
        if i//100 + i % 10 == i//10 % 10 * 2:
            ans += 1
    print(ans)
