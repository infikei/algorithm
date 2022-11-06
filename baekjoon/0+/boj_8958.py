n = int(input())
for i in range(n):
    oxox = input()
    cumulative = score = 0

    for j in range(len(oxox)):
        if oxox[j] == 'O':
            cumulative += 1
            score += cumulative
        else:
            cumulative = 0

    print(score)
