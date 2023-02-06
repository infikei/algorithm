def gcd(a, b):
    if a < b:
        a, b = b, a
    if a % b == 0:
        return b
    return gcd(b, a % b)


for t in range(int(input())):
    a, b = map(int, input().split())
    print(int(a*b/gcd(a, b)))
