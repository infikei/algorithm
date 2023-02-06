n = int(input())
stack, ans = [], []
max = 0
possible = True

for i in range(n):
    now = int(input())
    while now > max:
        max += 1
        stack.append(max)
        ans.append("+")

    if stack[-1] == now:
        stack.pop()
        ans.append("-")
    else:
        possible = False
        break

if possible:
    print(*ans, sep='\n')
else:
    print("NO")
