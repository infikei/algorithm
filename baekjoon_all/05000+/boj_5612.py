# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
m = int(input())

m_min = m_max = m
for _ in range(n):
    u, v = map(int, input().split())
    m += u - v
    m_min = min(m_min, m)
    m_max = max(m_max, m)

if m_min < 0:
    print(0)
else:
    print(m_max)
