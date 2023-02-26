# Solve 2023-02-26

n, k = map(int, input().split())
scores = list(sorted(map(int, input().split()), reverse=True))

print(scores[k - 1])
