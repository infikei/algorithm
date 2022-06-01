hour, minute = map(int, input().split())

result = int(input())
result += hour*60 + minute

print(result//60 % 24, result % 60)
