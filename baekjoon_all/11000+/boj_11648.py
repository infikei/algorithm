# Solve 2023-12-21

n = input()
ans = 0

while len(n) > 1:
    n = map(int, list(n))
    digit_prod = 1

    for d in n:
        digit_prod *= d

    n = str(digit_prod)
    ans += 1

print(ans)
