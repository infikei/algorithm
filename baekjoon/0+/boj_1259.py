while True:
    n = input()
    if n == '0':
        break
    p = True
    for i in range(len(n)//2):
        if n[i] != n[len(n)-1-i]:
            p = False
            break
    if p:
        print("yes")
    else:
        print("no")
