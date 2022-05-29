n = int(input())

for i in range(n):
    print(" "*i+"*"*(2*n-1-2*i))
for i in range(n-1):
    print(" "*(n-2-i)+"*"*(2*i+3))
