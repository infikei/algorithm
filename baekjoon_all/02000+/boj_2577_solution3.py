# Solve 2022-05-19
# Update 2025-07-20

from collections import Counter

abc = Counter(list(str(int(input()) * int(input()) * int(input()))))

for d in range(10):
    print(abc[str(d)])
