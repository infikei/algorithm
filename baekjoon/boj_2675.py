T = int(input())

for t in range(T):
    R, S = input().split()
    R = int(R)
    result = ""
    for s in S:
        result += s * R
    print(result)