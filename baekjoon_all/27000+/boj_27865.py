# Solve 2023-03-10
# Update 2023-12-24

import sys

input = lambda : sys.stdin.readline().rstrip()
flush = lambda : sys.stdout.flush()

n = int(input())

while True:
    print("? 1")
    flush()
    response = input()

    if response == "Y":
        break

print("! 1")
