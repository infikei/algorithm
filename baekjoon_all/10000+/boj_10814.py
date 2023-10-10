# Solve 2022-05-30
# Update 2023-10-10

n = int(input())
members = [[] for _ in range(201)]

for _ in range(n):
    age, name = input().split()
    age = int(age)
    members[age].append((age, name))

for li in members:
    for member in li:
        print(*member)
