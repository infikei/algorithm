# Solve 2023-12-23

from collections import Counter

_ = input()
cnt = Counter(map(lambda x: int(x) % 2, input().split()))
print("Happy" if cnt[0] > cnt[1] else "Sad")
