def hanoi(n, before=1, after=3):
    if n == 1:
        return 1, "%d %d\n" % (before, after)

    count1, str1 = hanoi(n-1, before, 6-before-after)
    count2, str2 = hanoi(1, before, after)
    count3, str3 = hanoi(n-1, 6-before-after, after)
    return count1+count2+count3, str1+str2+str3


count0, str0 = hanoi(int(input()))
print(count0)
print(str0.rstrip())
