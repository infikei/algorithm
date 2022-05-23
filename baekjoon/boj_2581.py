from math import sqrt


def isPrime(n):
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True


m = max(int(input()), 2)
n = int(input())

li = []
for i in range(m, n+1):
    if isPrime(i):
        li.append(i)
if li == []:
    print(-1)
else:
    print(sum(li))
    print(min(li))
