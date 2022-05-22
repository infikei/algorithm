# solution 1. 그냥코딩

x = int(input())
line = 1
while True:
    if x <= line*(line+1)/2:
        break
    line += 1
a = int(x-line*(line-1)/2)
b = int(line+1-a)
if line % 2:
    print(b, "/", a, sep="")
else:
    print(a, "/", b, sep="")
