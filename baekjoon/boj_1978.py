from math import sqrt


def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True


n = int(input())
li = list(map(int, input().split()))
ans = 0
for i in li:
    if isPrime(i):
        ans += 1
print(ans)
