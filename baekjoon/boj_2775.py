for i in range(int(input())):
    k = int(input())
    n = int(input())
    li = list(range(1, n+1))
    for ii in range(1, k):
        for iii in range(1, n):
            li[iii] += li[iii-1]
    print(sum(li))
