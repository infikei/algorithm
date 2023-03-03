# Solve 2023-03-03

def calc_big_fibonacci(k):
    if k == 0:
        return 0
    f_val = [0, 0, 1]
    for _ in range(2, k + 1):
        f_val[0:2] = f_val[1:3]
        f_val[2] = sum(f_val[0:2])
    return f_val[2]

n = int(input())

print(calc_big_fibonacci(n))
