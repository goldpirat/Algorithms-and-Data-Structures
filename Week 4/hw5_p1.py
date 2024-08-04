import time
import math
import matplotlib.pyplot as plt

# 1. Naive Recursive
def fib_naive(n):
    if n <= 1:
        return n
    else:
        return fib_naive(n-1) + fib_naive(n-2)

# 2. Bottom-Up
def fib_bottom_up(n):
    fib_numbers = [0, 1]
    for i in range(2, n+1):
        fib_numbers.append(fib_numbers[i-1] + fib_numbers[i-2])
    return fib_numbers[n]

# 3. Closed Form
def fib_closed_form(n):
    phi = (1 + math.sqrt(5)) / 2
    return int(phi**n / math.sqrt(5))

# 4. Matrix Representation
def fib_matrix(n):
    def multiply(F, M):
        x = F[0][0] * M[0][0] + F[0][1] * M[1][0]
        y = F[0][0] * M[0][1] + F[0][1] * M[1][1]
        z = F[1][0] * M[0][0] + F[1][1] * M[1][0]
        w = F[1][0] * M[0][1] + F[1][1] * M[1][1]
        F[0][0], F[0][1], F[1][0], F[1][1] = x, y, z, w

    def power(F, n):
        if n == 0 or n == 1:
            return
        M = [[1, 1],
             [1, 0]]
        power(F, n // 2)
        multiply(F, F)
        if n % 2 != 0:
            multiply(F, M)

    if n == 0:
        return 0
    F = [[1, 1],
         [1, 0]]
    power(F, n - 1)
    return F[0][0]

# Function to measure running time
def measure_time(func, n):
    start = time.time()
    func(n)
    end = time.time()
    return end - start

# Measuring and plotting
n_values = [0, 1, 2, 3, 4, 5, 6, 8, 10, 13, 16, 20, 25, 32, 40]  # Sample n values, adjust as needed
methods = [fib_naive, fib_bottom_up, fib_closed_form, fib_matrix]
times = {method.__name__: [] for method in methods}

# Adjust your sample `n_values` as needed based on performance
for n in n_values:
    for method in methods:
        try:
            elapsed_time = measure_time(method, n)
            times[method.__name__].append(elapsed_time)
        except:
            times[method.__name__].append(None)

# Plotting
plt.figure(figsize=(10, 6))
for method_name, timings in times.items():
    plt.plot(n_values, timings, label=method_name)
plt.xlabel('n')
plt.ylabel('Time (seconds)')
plt.title('Fibonacci Computation Times')
plt.yscale('log')
plt.legend()
plt.show()
