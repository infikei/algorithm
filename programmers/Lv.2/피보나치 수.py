# Solve 2023-03-19

def solution(n):
    answer = 0

    li = [0, 0, 1]
    for i in range(2, n + 1):
        li[0] = li[1]
        li[1] = li[2]
        li[2] = (li[0] + li[1]) % 1234567

    answer = li[2]

    return answer
