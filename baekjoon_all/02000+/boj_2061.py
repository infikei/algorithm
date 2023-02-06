# 백준 1837번과 같은 문제

K, L = map(int, input().split())
check = True

for i in range(2, L):
    if K % i == 0:
        check = False
        print("BAD %d" % i)
        break

if check:
    print("GOOD")