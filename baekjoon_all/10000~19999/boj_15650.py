def dfs(k=0):
    if len(s) == m:
        print(*s)
    else:
        for i in range(k+1, n+1):
            s.append(i)
            dfs(i)
            s.pop()


n, m = map(int, input().split())
s = []

dfs()
