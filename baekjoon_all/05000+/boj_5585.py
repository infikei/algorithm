# Solve 2023-08-28

money_li = [500, 100, 50, 10, 5, 1]
x, cnt = 1000 - int(input()), 0

for money in money_li:
    cnt += x // money
    x %= money

print(cnt)
