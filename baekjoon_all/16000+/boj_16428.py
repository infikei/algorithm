# Solve 2023-11-09

a, b = map(int, input().split())
q, r = divmod(a, b)

if r < 0:
    if b > 0:
        r += b
        q -= 1
    else:
        r -= b
        q += 1

print(q)
print(r)
