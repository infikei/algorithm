def dfs():
    if len(s) == m:
        print(" ".join(map(str, s)))
    else:
        for i in range(1, n+1):
            s.append(i)
            dfs()
            s.pop()


n, m = map(int, input().split())
s = []

dfs()
