# Solve 2022-05-31
# Update 2023-08-02

l, p = map(int, input().split())
li = map(lambda x: int(x) - l * p, input().split())
print(*li)
