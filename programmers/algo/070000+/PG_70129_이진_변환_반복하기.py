# Solve 2023-03-19

def solution(s):
    answer = [0] * 2

    while s != "1":
        ones = s.count("1")
        answer[1] += len(s) - ones
        answer[0] += 1
        s = bin(ones)[2:]

    return answer
