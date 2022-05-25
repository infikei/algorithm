n = int(input())
kgcm = []
for i in range(n):
    kg, cm = map(int, input().split())
    kgcm.append((kg, cm))

rank = [0] * n
for i in range(n):
    rank_i = 1
    kg_i, cm_i = kgcm[i]
    for j in range(n):
        kg_j, cm_j = kgcm[j]
        if kg_j > kg_i and cm_j > cm_i:
            rank_i += 1
    rank[i] = rank_i

print(*rank)
