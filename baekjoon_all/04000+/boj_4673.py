# Solve 2022-05-19
# Update 2023-03-07

nums = set(range(1, 10001))
remove_nums = set()

for num in nums:
    for ch in str(num):
        num += int(ch)
    remove_nums.add(num)

print(*sorted(nums - remove_nums), sep="\n")
