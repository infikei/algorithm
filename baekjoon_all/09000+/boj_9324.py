# Solve 2023-12-12

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    s = input()
    cnt = [0] * 26
    ans = True
    pos = 0

    while pos < len(s):
        idx = ord(s[pos]) - ord("A")
        cnt[idx] += 1

        if cnt[idx] == 3:
            cnt[idx] = 0
            pos += 1

            if pos >= len(s) or s[pos - 1] != s[pos]:
                ans = False
                break

        pos += 1

    if ans:
        print("OK")
    else:
        print("FAKE")
