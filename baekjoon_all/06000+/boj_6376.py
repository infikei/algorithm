# Solve 2023-03-07

print("n e")
print("-", "-" * 11)

e = 0
fac = 1
for i in range(0, 10):
    if i > 0:
        fac *= i
    e += 1 / fac

    if i >= 3:
        print("%d %.9f" % (i, e))
    elif i == 2:
        print("%d %.1f" % (i, e))
    else:
        print("%d %.0f" % (i, e))
