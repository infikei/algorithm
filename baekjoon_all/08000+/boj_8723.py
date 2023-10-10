# Solve 2023-10-10

nums = sorted(map(int, input().split()))

if nums[0] == nums[2]:
    print(2)
elif nums[0] ** 2 + nums[1] ** 2 == nums[2] ** 2:
    print(1)
else:
    print(0)
