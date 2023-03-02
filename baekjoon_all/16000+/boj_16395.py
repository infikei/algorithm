# Solve 2023-03-02

n, k = map(int, input().split())
pascal_triangle = [[1] * n for _ in range(n)]
for row in range(2, n):
    for col in range(1, row):
        pascal_triangle[row][col] = pascal_triangle[row - 1][col - 1] + pascal_triangle[row - 1][col]
print(pascal_triangle[n - 1][k - 1])
