# Solve 2022-05-16
# Update 2023-02-22

a, b = map(int, input().split())
if a < b:
    print("<")
elif a > b:
    print(">")
else:
    print("==")
