# Solve 2022-05-26
# Update 2023-03-23

n = int(input())
cnt = 0
ans = 665
while True:
    ans += 1
    if "666" in str(ans):
        cnt += 1
        if cnt == n:
            break

print(ans)
