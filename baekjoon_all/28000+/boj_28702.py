# Solve 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

def fizzbuzz(x):
    if x % 15 == 0:
        return "FizzBuzz"
    elif x % 3 == 0:
        return "Fizz"
    elif x % 5 == 0:
        return "Buzz"
    else:
        return x


nums = [input() for _ in range(3)]

for i in range(3):
    if nums[i][0] not in "FB":
        nxt_num = int(nums[i]) + (3 - i)
        print(fizzbuzz(nxt_num))
        break
