# Solve 2023-10-07

import sys

li = list(map(int, sys.stdin.read().rstrip().split()))
li.pop()

for n in li:
    proper_divisors_of_n = []

    for i in range(1, n):
        if n % i == 0 and i not in proper_divisors_of_n:
            proper_divisors_of_n.append(i)

    sum_of_proper_divisors = sum(proper_divisors_of_n)

    if sum_of_proper_divisors < n:
        print("%d DEFICIENT" % n)
    elif sum_of_proper_divisors > n:
        print("%d ABUNDANT" % n)
    else:
        print("%d PERFECT" % n)
