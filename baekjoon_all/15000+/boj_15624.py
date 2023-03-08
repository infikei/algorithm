# Solve 2023-03-07

MOD = 1000000007

def calc_fibonacci(k):
    if k == 0:
        return 0
    val = [0, 0, 1]
    for _ in range(2, k + 1):
        val[0:2] = val[1:3]
        val[2] = (val[0] + val[1]) % MOD
    return val[2]

n = int(input())

print(calc_fibonacci(n))
