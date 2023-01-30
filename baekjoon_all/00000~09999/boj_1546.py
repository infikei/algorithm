n = int(input())
score = list(map(int, input().split()))
sum = max = 0
for i in score:
    if i > max:
        max = i
    sum += i
print(sum / n / max * 100)
