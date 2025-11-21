# Solve 2025-11-20

a, b = input().split()
b = int(b)

d, f = a.split(".")
x = int(d + f)
f_len = len(f)

ans = str(x ** b)
f_len *= b

if len(ans) <= f_len:
    ans = "0." + "0" * (f_len - len(ans)) + ans
else:
    ans = ans[:len(ans) - f_len] + "." + ans[len(ans) - f_len:]

print(ans)
