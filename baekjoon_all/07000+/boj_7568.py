# Solve 2022-05-26
# Update 2023-10-25

n = int(input())
kg_and_cm = [list(map(int, input().split())) for _ in range(n)]
rank = [1] * n

for i in range(n):
    for j in range(i + 1, n):
        if kg_and_cm[i][0] > kg_and_cm[j][0] and kg_and_cm[i][1] > kg_and_cm[j][1]:
            rank[j] += 1
        elif kg_and_cm[i][0] < kg_and_cm[j][0] and kg_and_cm[i][1] < kg_and_cm[j][1]:
            rank[i] += 1

print(*rank)
