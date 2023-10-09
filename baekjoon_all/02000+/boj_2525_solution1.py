# Solve 2022-05-16
# Update 2023-10-09

hour, minute = map(int, input().split())
extra = int(input())

ans = hour * 60 + minute + extra

print(ans // 60 % 24, ans % 60)
