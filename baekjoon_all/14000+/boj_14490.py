# Solve 2023-03-03

def calc_gcd(a, b):
    if a % b == 0:
        return b
    return calc_gcd(b, a % b)

n, m = map(int, input().split(":"))
gcd = calc_gcd(n, m)
print("%d:%d" % (n // gcd, m // gcd))
