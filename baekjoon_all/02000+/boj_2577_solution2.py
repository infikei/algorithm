# Solve 2022-05-19
# Update 2024-02-15

abc = int(input()) * int(input()) * int(input())
abc = list(str(abc))

for d in range(10):
    print(abc.count(str(d)))
