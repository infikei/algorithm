# Solve 2022-05-26
# Update 2024-02-27

n = int(input())
memo = [0, 0]

for i in range(2, n + 1):
    memo.append(memo[i - 1])

    if i % 2 == 0:
        memo[i] = min(memo[i], memo[i // 2])

    if i % 3 == 0:
        memo[i] = min(memo[i], memo[i // 3])

    memo[i] += 1

print(memo[n])
