# Solve 2023-10-09

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

tunnel_in = dict()

for i in range(n):
    car = input()

    tunnel_in[car] = i

tunnel_out = []

for _ in range(n):
    car = input()

    tunnel_out.append(tunnel_in[car])

ans = 0

for i in range(n):
    for j in range(i + 1, n):
        if tunnel_out[i] > tunnel_out[j]:
            ans += 1
            break

print(ans)
