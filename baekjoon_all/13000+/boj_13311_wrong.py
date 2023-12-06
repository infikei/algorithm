# Solve 2023-12-05

# 이 풀이는 잘못된 풀이이지만, 재미삼아 남겨두었습니다.

def calc_gcd(a, b):
    r = a % b
    if r == 0:
        return b
    return calc_gcd(b, r)

def calc_lcm(a, b):
    return a * b // calc_gcd(a, b)

ans = 1

for i in range(2, 1001):
    ans = calc_lcm(ans, i)

ans -= 1

print(ans)
