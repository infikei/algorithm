# Solve 2023-03-19

def solution(s):
    answer = ""

    li = list(map(int, s.split()))
    answer = "%d %d" % (min(li), max(li))

    return answer
