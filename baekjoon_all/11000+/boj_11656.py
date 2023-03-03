# Solve 2023-03-03

s = input()
li = [s[i:] for i in range(len(s))]

print(*sorted(li), sep="\n")
