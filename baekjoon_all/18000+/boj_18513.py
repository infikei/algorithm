# Solve 2025-11-18

n, k = map(int, input().split())
li = sorted(map(int, input().split()))
imos = {1: 2 * n}

for i in range(1, n):
    gap = li[i] - li[i - 1] - 1

    if gap % 2 == 0:
        imos[gap // 2 + 1] = imos.get(gap // 2 + 1, 0) - 2
    else:
        imos[gap // 2 + 1] = imos.get(gap // 2 + 1, 0) - 1
        imos[gap // 2 + 2] = imos.get(gap // 2 + 2, 0) - 1

ans = 0
level = 0
prefix_sum = 0

while k > 0:
    level += 1
    prefix_sum += imos.get(level, 0)

    ans += level * min(k, prefix_sum)
    k -= prefix_sum

print(ans)
