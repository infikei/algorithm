# Solve 2023-03-07

for a in range(2, 101):
    a3 = a ** 3
    for b in range(2, a):
        b3 = b ** 3
        for c in range(b, a):
            c3 = c ** 3
            for d in range(c, a):
                d3 = d ** 3
                if a3 == b3 + c3 + d3:
                    print("Cube = %d, Triple = (%d,%d,%d)" % (a, b, c, d))
