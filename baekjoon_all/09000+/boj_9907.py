# Solve 2023-12-15

weights = [2, 7, 6, 5, 4, 3, 2]
digits = input()
idx = sum(map(lambda d, w: int(d) * w, digits, weights)) % 11
print("JABCDEFGHIZ"[idx])
