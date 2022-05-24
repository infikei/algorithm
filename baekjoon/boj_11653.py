def divide(n, i):
    if n % i == 0:
        print(i)
        return divide(n/i, i)
    else:
        return (n, i)


n = int(input())
for i in range(2, n+1):
    n, i = divide(n, i)
    if n == 1:
        break
