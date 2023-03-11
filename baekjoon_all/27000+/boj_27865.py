# Solve 2023-03-10

import sys

input = lambda : sys.stdin.readline().rstrip()
flush = lambda : sys.stdout.flush()

n = int(input())

while True:
    print("? 1")
    flush()
    ch = input()
    if ch == "Y":
        break

print("! 1")
