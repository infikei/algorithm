# Solve 2023-03-19

def solution(A,B):
    answer = 0

    A.sort()
    B.sort(reverse=True)

    n = len(A)
    for i in range(n):
        answer += A[i] * B[i]

    return answer
