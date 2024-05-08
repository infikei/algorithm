# Solve 2024-05-08

t = int(input())

for tc in range(1, t + 1):
    n = int(input())
    lst = list(map(int, input().split()))
    ans = -1

    for i in range(len(lst)):
        for j in range(i + 1, len(lst)):
            curNum = lst[i] * lst[j]
            curStr = str(curNum)
            flag = True

            for k in range(1, len(curStr)):
                if int(curStr[k - 1]) > int(curStr[k]):
                    flag = False
                    break

            if flag:
                ans = max(ans, curNum)

    print(f"#{tc} {ans}")
