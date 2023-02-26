# Solve 2022-05-20
# Update 2023-02-26

croatian_alphabets = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
word = input()

for cro in croatian_alphabets:
    word = word.replace(cro, "#")

print(len(word))
