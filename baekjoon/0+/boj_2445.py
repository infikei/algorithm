n = int(input())

for i in range(n-1):
    print("*"*(i+1)+" "*(2*n-2-2*i)+"*"*(i+1))
print("*"*(2*n))
for i in range(n-1):
    print("*"*(n-1-i)+" "*(2*i+2)+"*"*(n-1-i))
