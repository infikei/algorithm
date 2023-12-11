# Solve 2023-12-11

for aaa in range(100, 1000):
    for bbb in range(100, 1000):
        if aaa % 10 != bbb // 100:
            continue
        if aaa % 111 == 0:
            continue

        aa = aaa // 10
        bb = bbb % 100

        if aaa * bb == bbb * aa:
            print("%d / %d = %d / %d" % (aaa, bbb, aa, bb))
