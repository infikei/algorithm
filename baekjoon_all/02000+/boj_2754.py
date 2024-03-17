# Solve 2023-03-03
# Update 2024-03-17

grade = input()
score = 0

if grade != "F":
    score = 4 - (ord(grade[0]) - ord("A"))

    if grade[1] == "+":
        score += 0.3
    elif grade[1] == "-":
        score -= 0.3

print("%.1f" % score)
