# Solve 2023-02-26

def make_triangle(k):
    if k == 3:
        return ["  *  ", " * * ", "*****"]

    k2 = k // 2
    small_triangle = make_triangle(k2)
    triangle = []

    for line in small_triangle:
        triangle.append(" " * k2 + line + " " * k2)
    for line in small_triangle:
        triangle.append(line + " " + line)

    return triangle

n = int(input())

print(*make_triangle(n), sep="\n")
