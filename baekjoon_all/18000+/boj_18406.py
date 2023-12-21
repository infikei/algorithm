# Solve 2023-12-21

n = input()
left_sum = sum(map(int, n[:len(n) // 2]))
right_sum = sum(map(int, n[len(n) // 2:]))

print("LUCKY" if left_sum == right_sum else "READY")
