# Solve 2022-05-19
# Update 2023-10-10

word = input().upper()
max_cnt = 0
max_char = []

for ch in set(word):
    cnt = word.count(ch)

    if cnt > max_cnt:
        max_char.clear()
        max_char.append(ch)
        max_cnt = cnt
    elif cnt == max_cnt:
        max_char.append(ch)

if len(max_char) > 1:
    print("?")
else:
    print(max_char[0])
