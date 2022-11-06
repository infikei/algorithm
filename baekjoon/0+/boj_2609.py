# 유클리드 호제법(Euclidean Algorithm)을 사용하여 최대공약수를 구한다.

def gcd(a, b):
    if a < b:
        a, b = b, a
    if a % b == 0:
        return b
    return gcd(b, a % b)


a, b = map(int, input().split())
gcd = gcd(a, b)  # 최대공약수 (Greatest Common Divisor)
lcm = int(a*b/gcd)  # 최소공배수 (Least Common Multiple)
print(gcd, lcm, sep='\n')
