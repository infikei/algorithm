# N = int(input())
# if N == 4 or N == 7:
#     print(-1)
# else:
#     a = N // 15 * 3
#     b = N % 15
#     dic1 = {0: 0, 5: 1, 6: 2, 8: 2, 9: 3, 10: 2, 11: 3, 12: 4, 13: 3, 14: 4}
#     dic2 = {16: 4, 17: 5, 18: 4, 19: 5, 22: 6}
#     if b in dic1:
#         print(a+dic1[b])
#     else:
#         a -= 3
#         b += 15
#         print(a+dic2[b])

# 요약

N = int(input())
dic1 = {0: 0, 5: 1, 6: 2, 8: 2, 9: 3, 10: 2, 11: 3, 12: 4, 13: 3, 14: 4}
dic2 = {1: 1, 2: 2, 3: 1, 4: 2, 7: 3}
a, b = N // 15 * 3, N % 15
if N == 4 or N == 7:
    print(-1)
else:
    print(a+dic1[b]) if b in dic1 else print(a+dic2[b])
