def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


prime_numbers = []

for i in range(2, 246913):
    if isPrime(i):
        prime_numbers.append(i)

while True:
    n = int(input())
    if n == 0:
        break
    ans = 0
    for i in prime_numbers:
        if i > n and i <= 2*n:
            ans += 1
    print(ans)
