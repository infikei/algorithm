# solution 2. 수식 활용한 버전

# from math import ceil, sqrt
# x = int(input())
# y = ceil((sqrt(8*x+1)-1)/2)
# son = int(x-y*(y-1)/2)
# mother = int(y+1-son)
# if y % 2 == 0:
#     print("{}/{}".format(son, mother))
# else:
#     print("{}/{}".format(mother, son))

# solution 2. 수식 활용한 버전 - 요약

from math import ceil, sqrt
x = int(input())
y = ceil((sqrt(8*x+1)-1)/2)
a = int(x-y*(y-1)/2)
b = int(y+1-a)
if y % 2:
    print(b, "/", a, sep="")
else:
    print(a, "/", b, sep="")
