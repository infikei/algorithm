n, m = map(int, input().split())
li = list(map(int, input().split()))
ans = 0
i, j, k = 0, 1, 2

while True:
    temp_sum = li[i]+li[j]+li[k]
    if ans < temp_sum <= m:
        ans = temp_sum
        if ans == m:
            break
    k += 1
    if k == n:
        j += 1
        if j == n-1:
            i += 1
            if i >= n-2:
                break
            j = i+1
        k = j+1
print(ans)
