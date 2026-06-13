# Solve 2026-06-10

while (n := int(''.join(list(reversed(input()))))) != 0:
    print(n, sum(map(int, list(str(n)))))
