a, b = map(int, input().split())
new_a = a % 10 * 100 + a//10 % 10 * 10 + a//100
new_b = b % 10 * 100 + b//10 % 10 * 10 + b//100
if new_a > new_b:
    print(new_a)
else:
    print(new_b)