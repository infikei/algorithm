def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


while True:
    n = int(input())
    if n == 0:
        break
    ans = 0
    for i in range(n+1, 2*n+1):
        if isPrime(i):
            ans += 1
    print(ans)
