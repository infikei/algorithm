# Solve 2023-10-13

a, b, c, m = map(int, input().split())

fatigue = done = 0

for hour in range(0, 24):
    if fatigue + a <= m:
        fatigue += a
        done += b
    else:
        fatigue -= c

    if fatigue < 0:
        fatigue = 0

print(done)
