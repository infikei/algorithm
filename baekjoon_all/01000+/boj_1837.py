P, K = map(int, input().split())
check = True

for i in range(2, K):
    if P % i == 0:
        check = False
        print("BAD %d" % i)
        break

if check:
    print("GOOD")