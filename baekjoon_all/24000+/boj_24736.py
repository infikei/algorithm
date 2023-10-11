# Solve 2022-06-02
# Update 2023-10-11

scores = [0] * 2

for i in range(2):
    t, f, s, p, c = map(int, input().split())

    scores[i] = 6 * t + 3 * f + 2 * s + p + 2 * c

print(*scores)
