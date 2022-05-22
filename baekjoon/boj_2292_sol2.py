# solution 2. 수식 활용한 버전

# from math import ceil, sqrt
# x = int(input())
# k = ceil((x-1)/6)
# y = ceil((sqrt(8*k+1)-1)/2)+1
# print(y)

# solution 2. 수식 활용한 버전 - 요약

from math import ceil, sqrt
print(ceil((sqrt(8*ceil((int(input())-1)/6)+1)-1)/2)+1)
