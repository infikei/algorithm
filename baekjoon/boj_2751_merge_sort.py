# Merge Sort (병합 정렬) 알고리즘을 이용한다.

import sys


def merge_sort(array):
    if len(array) <= 1:
        return array

    # 분할 (Divide)
    center = len(array)//2
    left = merge_sort(array[:center])
    right = merge_sort(array[center:])

    # 정복 (Conquer) 및 결합 (Combine)

    i, j, k = 0, 0, 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k += 1
    if i == len(left):
        while j < len(right):
            array[k] = right[j]
            j += 1
            k += 1
    elif j == len(right):
        while i < len(left):
            array[k] = left[i]
            i += 1
            k += 1
    return array


s = []
for i in range(int(sys.stdin.readline())):
    s.append(int(sys.stdin.readline()))

s = merge_sort(s)
print(*s, sep='\n')
