n = int(input()) * int(input()) * int(input())
arr = list(str(n))

for i in range(10):
    print(arr.count(str(i)))
