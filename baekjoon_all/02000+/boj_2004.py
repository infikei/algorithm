# Solve 2023-10-09
# Update 2025-11-12

n, m = map(int, input().split())

cnt5, i = 0, 5

while i <= n:
    cnt5 += n // i
    cnt5 -= m // i
    cnt5 -= (n - m) // i

    i *= 5

cnt2, i = 0, 2

while i <= n:
    cnt2 += n // i
    cnt2 -= m // i
    cnt2 -= (n - m) // i

    i *= 2

print(min(cnt5, cnt2))
