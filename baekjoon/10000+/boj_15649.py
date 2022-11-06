# 백트래킹 Backtracking

def dfs():
    if len(s) == m:
        print(' '.join(map(str, s)))
    else:
        for i in range(1, n+1):
            if visited[i]:
                continue
            visited[i] = True
            s.append(i)
            dfs()
            s.pop()
            visited[i] = False


n, m = map(int, input().split())
visited = [False] * (n+1)
s = []

dfs()
