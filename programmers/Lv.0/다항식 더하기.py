# Solve 2023-03-19

def solution(polynomial):
    answer = ""

    res = [0] * 2

    terms = polynomial.split(" + ")
    for term in terms:
        if term[-1] == "x":
            if term == "x":
                res[0] += 1
            else:
                res[0] += int(term[:-1])
        else:
            res[1] += int(term)

    if res[0] > 0:
        if res[0] == 1:
            answer = "x"
        else:
            answer = "%dx" % res[0]
    if res[1] > 0:
        if answer == "":
            answer = "%d" % res[1]
        else:
            answer += " + %d" % res[1]

    return answer
