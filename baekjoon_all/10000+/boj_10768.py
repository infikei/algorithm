# Solve 2023-12-19
# Update 2025-02-25

import sys

input = lambda : sys.stdin.readline().rstrip()

mmdd = int(input()) * 100 + int(input())

if mmdd < 218:
    print("Before")
elif mmdd > 218:
    print("After")
else:
    print("Special")
