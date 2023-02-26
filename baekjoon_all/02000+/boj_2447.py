# Solve 2022-05-25
# Update 2023-02-26

def make_square(k):
    if k == 1:
        return ["*"]

    small_square = make_square(k // 3)
    square = []

    for line in small_square:
        square.append(line * 3)
    for line in small_square:
        square.append(line + " " * (k // 3) + line)
    for line in small_square:
        square.append(line * 3)

    return square

n = int(input())

print(*make_square(n), sep="\n")
