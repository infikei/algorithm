# Solve 2022-05-19
# Update 2023-02-26

word = input().upper()
max_cnt = 0
max_char = []

for now_char in set(word):
    now_cnt = word.count(now_char)
    if now_cnt > max_cnt:
        max_char.clear()
        max_char.append(now_char)
        max_cnt = now_cnt
    elif now_cnt == max_cnt:
        max_char.append(now_char)

if len(max_char) > 1:
    print("?")
else:
    print(max_char[0])
