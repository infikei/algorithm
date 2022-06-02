n = int(input()) * int(input()) * int(input())

arr = []
while n > 0:
    arr.append(n % 10)
    n = n//10
for i in range(10):
    print(arr.count(i))
