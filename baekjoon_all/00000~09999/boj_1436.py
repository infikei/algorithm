n = int(input())

i, ans = 0, 665
while True:
    ans += 1
    if "666" in str(ans):
        i += 1
        if i == n:
            break
print(ans)
