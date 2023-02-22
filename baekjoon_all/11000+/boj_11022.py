# Solve 2022-05-16
# Update 2023-02-22

t = int(input())

for ti in range(t):
    a, b = map(int, input().split())
    print("Case #%d: %d + %d = %d" % (ti + 1, a, b, a + b))
