# 소수를 2 이상의 범위에서 찾을 것이므로, 소수 조사 시 1에 대한 코드를 생략할 수 있다.
def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


# n의 최댓값이 123456이므로 2부터 246912까지의 소수를 list에 미리 저장한다.
prime_numbers = []
for i in range(2, 246913):
    if isPrime(i):
        prime_numbers.append(i)

# 각각의 n 값을 입력받고, 답을 출력한다.
while True:
    n = int(input())
    if n == 0:
        break
    ans = 0
    for i in prime_numbers:
        if i > n and i <= 2*n:
            ans += 1
    print(ans)
