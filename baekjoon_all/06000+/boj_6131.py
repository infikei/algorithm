# Solve 2023-03-08
# Update 2023-10-08

n = int(input())
ans = 0

for a in range(1, 501):
    a2 = a * a

    for b in range(1, a + 1):
        b2 = b * b

        if a2 == b2 + n:
            ans += 1

print(ans)
