ans = 0
for i in range(int(input())):
    word = input()
    li = list(set(word))
    groupword = True
    for w in li:
        wordfind = word.find(w)
        for j in range(word.count(w)):
            if word[wordfind+j] != w:
                groupword = False
                break
        if not groupword:
            break
    if groupword:
        ans += 1
print(ans)
