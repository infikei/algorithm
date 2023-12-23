# Solve 2023-12-23

a = [3, 20, 120]
t1 = input().split()
t2 = input().split()

t1 = sum([int(t1[i]) * a[i] for i in range(3)])
t2 = sum([int(t2[i]) * a[i] for i in range(3)])

if t1 > t2:
    print("Max")
elif t1 < t2:
    print("Mel")
else:
    print("Draw")
