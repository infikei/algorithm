import sys
import collections

# 입력값 저장하기
n = int(sys.stdin.readline())
numbers_list = sys.stdin.readlines()
# numbers_list = list(map(lambda num: int(num.rstrip()), numbers))

# ans1 : 산술평균 구하기
numbers_sum = 0
for i in range(n):
    numbers_list[i] = num = int(numbers_list[i].rstrip())
    numbers_sum += num
ans1 = round(numbers_sum/n)

# ans2 : 중앙값 구하기
# ans4 : 범위 구하기
numbers_sorted = sorted(numbers_list)
ans2 = numbers_sorted[(n+1)//2-1]
ans4 = numbers_sorted[-1] - numbers_sorted[0]

# ans3 : 최빈값 구하기
cnt = collections.Counter(numbers_list).most_common()
most_count = cnt[0][1]
most_li = []
for i in range(len(cnt)):
    if cnt[i][1] < most_count:
        break
    else:
        most_li.append(cnt[i][0])

if len(most_li) == 1:
    ans3 = most_li[0]
else:
    ans3 = sorted(most_li)[1]

# 결과 출력하기
print(ans1)
print(ans2)
print(ans3)
print(ans4)
