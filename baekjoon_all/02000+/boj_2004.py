# Solve 2023-10-09

n, m = map(int, input().split())

cnt_5, i = 0, 5

while i <= n:
    cnt_5 += n // i
    cnt_5 -= m // i
    cnt_5 -= (n - m) // i

    i *= 5

cnt_2, i = 0, 2

while i <= n:
    cnt_2 += n // i
    cnt_2 -= m // i
    cnt_2 -= (n - m) // i

    i *= 2

print(min(cnt_5, cnt_2))
