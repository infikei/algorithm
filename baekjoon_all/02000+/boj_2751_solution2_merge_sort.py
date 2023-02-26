# Solve 2022-06-01
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

def merge_sort(li):
    if len(li) < 2:
        return li

    len_li = len(li)
    mid = len(li) // 2
    left_li, right_li = merge_sort(li[:mid]), merge_sort(li[mid:])

    i = j = 0
    for k in range(len_li):
        if i == mid:
            li[k] = right_li[j]
            j += 1
        elif j == len_li - mid:
            li[k] = left_li[i]
            i += 1
        elif left_li[i] < right_li[j]:
            li[k] = left_li[i]
            i += 1
        else:
            li[k] = right_li[j]
            j += 1

    return li

n = int(input())
li = merge_sort([int(input()) for _ in range(n)])

print(*li, sep="\n")
