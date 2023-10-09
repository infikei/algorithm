# Solve 2023-10-09

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())

never_heard = {input() for _ in range(n)}
never_seen = {input() for _ in range(m)}

never_heard_and_never_seen = sorted(never_heard & never_seen)

print(len(never_heard_and_never_seen))
print(*never_heard_and_never_seen, sep="\n")
