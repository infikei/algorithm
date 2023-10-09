# Solve 2023-03-07
# Update 2023-10-08

def calc_sum(k, mod):
    res = 0

    while k > 0:
        res += k % mod
        k //= mod

    return res

for num in range(1000, 10000):
    sum10 = calc_sum(num, 10)
    sum12 = calc_sum(num, 12)

    if sum10 != sum12: continue

    sum16 = calc_sum(num, 16)

    if sum10 != sum16: continue

    print(num)
