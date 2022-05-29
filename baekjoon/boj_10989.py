import sys

n = int(sys.stdin.readline())
s = [0] * 10001

for i in range(n):
    s[int(sys.stdin.readline())] += 1

for i in range(1, 10001):
    for j in range(s[i]):
        print(i)
