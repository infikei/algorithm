n = int(input())
line = [int(input())]

for t in range(2, n+1):
    newline = list(map(int, input().split()))
    for i in range(t):
        if i == 0:
            newline[i] += line[i]
        elif i == t-1:
            newline[i] += line[i-1]
        else:
            newline[i] += max(line[i-1], line[i])
    line = newline.copy()

print(max(line))
