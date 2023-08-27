# Solve 2023-01-09
# Update 2023-08-27

# 백준 같은 문제 : 1837번 = 2061번

p, k = map(int, input().split())

for i in range(2, k):
    if p % i == 0:
        print("BAD", i)
        break
else:
    print("GOOD")
