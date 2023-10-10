# Solve 2023-02-26
# Update 2023-10-10

n, k = map(int, input().split())
scores = sorted(map(int, input().split()), reverse=True)

print(scores[k - 1])
