word = input().upper()
max_w = []
max_n = 0

for w in set(word):
    n = word.count(w)
    if n > max_n:
        max_w.clear()
        max_w.append(w)
        max_n = n
    elif n == max_n:
        max_w.append(w)
if len(max_w) > 1:
    print("?")
else:
    print(max_w[0])
