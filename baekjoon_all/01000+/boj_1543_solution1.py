# Solve 2023-10-22

document = input()
word = input()
pos = 0
cnt = 0

while (pos := document.find(word, pos)) != -1:
    cnt += 1
    pos += len(word)

print(cnt)
