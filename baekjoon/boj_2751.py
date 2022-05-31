# 파이썬 내장 함수로 작성한 풀이이다.
# input() 함수 대신 sys.stdin.readline() 함수를 이용하여 시간을 단축한다.
# 또한, append 함수로 값을 저장하는 대신 list를 길이 n으로 초기화하고 값을 저장하여 시간을 단축한다.

import sys

n = int(sys.stdin.readline())
s = [0] * n

for i in range(n):
    s[i] = int(sys.stdin.readline())

print(*sorted(s), sep='\n')
