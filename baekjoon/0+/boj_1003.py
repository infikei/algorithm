dp = [(1, 0), (0, 1), (1, 1), (1, 2)]
for i in range(4, 41):
    a1, b1 = dp[i-2]
    a2, b2 = dp[i-1]
    dp.append((a1+a2, b1+b2))

for t in range(int(input())):
    print(*dp[int(input())])
