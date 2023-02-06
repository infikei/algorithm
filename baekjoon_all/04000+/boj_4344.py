C = int(input())
for i in range(C):
    (N, *score) = list(map(int, input().split()))
    s = 0
    for j in range(N):
        s += score[j]
    s /= N
    p = 0
    for j in range(N):
        if score[j] > s:
            p += 1
    p = p * 100 / N
    print('{:.3f}%'.format(p))
