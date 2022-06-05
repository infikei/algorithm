S = input()

if "a" in S:
    ans = str(S.find("a"))
else:
    ans = "-1"
for i in range(98, 123):
    if chr(i) in S:
        ans += " " + str(S.find(chr(i)))
    else:
        ans += " -1"
print(ans)