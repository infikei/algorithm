# Solve 2023-03-14
# Update 2023-08-28

s = input()

targets = ["JOI", "IOI"]

for target in targets:
    cnt = 0
    pos = s.find(target)

    while pos != -1:
        cnt += 1
        pos = s.find(target, pos + 1)

    print(cnt)
