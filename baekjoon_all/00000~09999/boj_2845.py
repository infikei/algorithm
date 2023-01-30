l, p = map(int, input().split())
li = map(lambda x: int(x)-l*p, input().split())
print(*li)
