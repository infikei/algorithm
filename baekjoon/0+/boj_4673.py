numbers = set(range(1, 10001))
remove_numbers = set()

for num in numbers:
    for n in str(num):
        num += int(n)
    remove_numbers.add(num)

s = "1"
for num in sorted(numbers - remove_numbers - {1}):
    s += ("\n"+str(num))
print(s)
