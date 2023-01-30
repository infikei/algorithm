a = [1, 1, 2, 2, 2, 8]
b = list(map(int, input().split()))
for i in range(6):
    a[i] -= b[i]
print(*a)
