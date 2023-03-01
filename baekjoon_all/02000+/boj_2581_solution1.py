# Solve 2022-05-24
# Update 2023-03-01

MAX_SIZE = 10001
primes = [True] * MAX_SIZE
primes[0] = primes[1] = False
for i in range(2, MAX_SIZE):
    if primes[i]:
        for j in range(i + i, MAX_SIZE, i):
            primes[j] = False

m = int(input())
n = int(input())

ans = []
for i in range(m, n + 1):
    if primes[i]:
        ans.append(i)

if len(ans) == 0:
    print(-1)
else:
    print(sum(ans))
    print(ans[0])
