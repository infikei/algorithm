# Solve 2022-05-16
# Update 2023-02-22

# Solution 1.

while True:
    try:
        print(sum(map(int, input().split())))
    except: # except EOFError:
        break
