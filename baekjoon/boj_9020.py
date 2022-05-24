# 소수를 2 이상의 범위에서 찾을 것이므로, 소수 조사 시 1에 대한 코드를 생략할 수 있다.
def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


# n의 최댓값이 10000이므로 2부터 10000까지의 소수를 list에 미리 저장한다.
prime_numbers = []
for i in range(2, 10001):
    if isPrime(i):
        prime_numbers.append(i)

# 각각의 n 값을 입력받고, 답을 출력한다.
# 예를 들어 n=9인 경우, 4+5, 3+6, 2+7 의 순서로 조사한다.
for i in range(int(input())):
    n = int(input())
    for j in range(n//2, 1, -1):
        if j in prime_numbers and (n-j) in prime_numbers:
            print(j, n-j)
            break
