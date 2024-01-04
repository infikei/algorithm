# Solve 2024-01-02

a, b = map(int, input().split())
c, d = map(int, input().split())
st = set(range(a, b)) | set(range(c, d))
print(len(st))
