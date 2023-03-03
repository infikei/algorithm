# Solve 2022-05-24
# Update 2023-03-03

n = int(input())

i = 2
while n > 1:
    while n % i == 0:
        print(i)
        n //= i
    i += 1
