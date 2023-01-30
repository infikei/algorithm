for t in range(int(input())):
    ps = input()
    vps = 0
    for s in ps:
        if s == "(":
            vps += 1
        else:
            vps -= 1
        if vps < 0:
            break
    if vps == 0:
        print("YES")
    else:
        print("NO")
