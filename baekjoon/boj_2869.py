# from math import ceil
# A, B, V = map(int, input().split())
# print(ceil((V-A)/(A-B))+1)

# math.ceil 함수를 사용하지 않고 코딩하려면 다음의 방법을 사용한다.
# 버림할 때는 //을 사용하면 된다.
# 올림할 때는 부호를 반대로 바꿔서 버림을 한다.

A, B, V = map(int, input().split())
print(1-(A-V)//(A-B))
