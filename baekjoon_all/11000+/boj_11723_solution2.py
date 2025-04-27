# Solve 2025-04-27

import sys
input = lambda: sys.stdin.readline().rstrip()

st = set()

for _ in range(int(input())):
    cmd = input()

    if cmd == "all":
        st = set([i for i in range(1, 21)])
        continue

    if cmd == "empty":
        st = set()
        continue

    cmd, x = cmd.split()
    x = int(x)

    if cmd == "add":
        st.add(x)
    elif cmd == "remove":
        if x in st:
            st.remove(x)
    elif cmd == "toggle":
        if x in st:
            st.remove(x)
        else:
            st.add(x)
    else:
        if x in st:
            print(1)
        else:
            print(0)
