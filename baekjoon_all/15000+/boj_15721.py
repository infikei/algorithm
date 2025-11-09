# Solve 2025-11-08

def solution(t, bd):
    b = d = 0
    loop = 2
    ret = 0

    while True:
        b += 1
        if t == b and bd == 0:
            return ret
        ret += 1

        d += 1
        if t == d and bd == 1:
            return ret
        ret += 1

        b += 1
        if t == b and bd == 0:
            return ret
        ret += 1

        d += 1
        if t == d and bd == 1:
            return ret
        ret += 1

        for i in range(loop):
            b += 1
            if t == b and bd == 0:
                return ret
            ret += 1

        for i in range(loop):
            d += 1
            if t == d and bd == 1:
                return ret
            ret += 1

        loop += 1


a, t, bd = int(input()), int(input()), int(input())
print(solution(t, bd) % a)
