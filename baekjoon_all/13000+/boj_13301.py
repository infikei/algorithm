# Solve 2023-03-02

n = int(input())

fibonacci_numbers = [1] * (n + 1)
for i in range(2, n + 1):
    fibonacci_numbers[i] = fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1]

print((fibonacci_numbers[n] + fibonacci_numbers[n - 1]) * 2)
