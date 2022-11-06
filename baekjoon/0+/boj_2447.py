def stars(n):
    if n == 1:
        return ['*']
    L3 = stars(n//3)
    L9 = []
    for star in L3:
        L9.append(star*3)
    for star in L3:
        L9.append(star+' '*(n//3)+star)
    for star in L3:
        L9.append(star*3)
    return L9


print("\n".join(stars(int(input()))))
