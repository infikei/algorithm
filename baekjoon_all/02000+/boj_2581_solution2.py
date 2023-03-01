# Solve 2022-05-24
# Update 2023-03-01

def is_prime(k):
    if k < 2:
        return False
    for i in range(2, int(k ** 0.5) + 1):
        if k % i == 0:
            return False
    return True

m = int(input())
n = int(input())

ans = []
for i in range(m, n + 1):
    if is_prime(i):
        ans.append(i)

if len(ans) == 0:
    print(-1)
else:
    print(sum(ans))
    print(ans[0])
