# Solve 2023-02-08
# Update 2024-06-19

n = int(input())

val = 1

for i in range(2, n + 1):
    val *= i

    while val % 10 == 0:
        val //= 10

    val %= 1000000 # 이것보다 작은 10의 거듭제곱으로 하면 n >= 15625 에서 오류가 생긴다.

val %= 10
print(val)

# 테스트케이스 모음

# 15624
# 6

# 15625
# 4

# 15626
# 4

# 19999
# 8

# 20000
# 6
