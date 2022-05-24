# def generator(n):
#     for i in str(n):
#         n += int(i)
#     return n


n = int(input())
ans = 0

for k in range(1, n):
    k_result = k
    for i in str(k):
        k_result += int(i)
    if k_result == n:
        ans = k
        break

print(ans)
