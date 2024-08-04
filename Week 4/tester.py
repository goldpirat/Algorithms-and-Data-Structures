"""
CH-231-A
hw5_p1.py
Flori Kusari
fkusari@jacobs-university.de
"""

import time
import math
import matplotlib.pyplot as plt


# Defining various Fibonacci sequence calculation methods.
# 1. Naive Recursive
# Recursive approach with simple base cases.


def recursive_fibonacci(inn):
    if inn <= 1:
        return inn
    return recursive_fibonacci(inn - 1) + recursive_fibonacci(inn - 2)


# 2. Bottom-Up
# Iterative approach, storing intermediate results.


def iterative_fibonacci(inn):
    sequence = [0, 1]
    for i in range(2, inn + 1):
        sequence.append(sequence[i - 1] + sequence[i - 2])
    return sequence[inn]


# 3. Closed Form
# Formula-based approach using Binet's formula.


def formula_fibonacci(i):
    golden_ratio = (1 + math.sqrt(5)) / 2
    return round(golden_ratio ** i / math.sqrt(5))


# 4. Matrix Representation
# Approach using matrix exponentiation for efficiency.


def matrix_fibonacci(inn):
    def matrix_multiply(matrix1, matrix2):
        a11 = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0]
        a12 = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1]
        a21 = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0]
        a22 = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1]
        matrix1[0][0], matrix1[0][1], matrix1[1][0], matrix1[1][1] = a11, a12, a21, a22

    def matrix_power(matt, exponent):
        if exponent in (0, 1):
            return
        base_matrix = [[1, 1], [1, 0]]
        matrix_power(matt, exponent // 2)
        matrix_multiply(matt, matt)
        if exponent % 2 != 0:
            matrix_multiply(matt, base_matrix)

    if inn == 0:
        return 0
    matt = [[1, 1], [1, 0]]
    matrix_power(matt, inn - 1)
    return matt[0][0]


# Runtime


def time_execution(fibonacci_function, value):
    start_time = time.time()
    fibonacci_function(value)
    end_time = time.time()
    return end_time - start_time


# Compare the performance of each Fibonacci calculation method.
# Measuring and plotting
sample_indices = [0, 1, 2, 3, 4, 5, 6, 8, 10, 13, 16, 20, 25, 32, 40]
fibonacci_methods = [recursive_fibonacci, iterative_fibonacci, formula_fibonacci, matrix_fibonacci]
execution_times = {method.__name__: [] for method in fibonacci_methods}

# Collecting execution times for various methods across different values of n.
for index in sample_indices:
    for fibonacci_method in fibonacci_methods:
        try:
            duration = time_execution(fibonacci_method, index)
            execution_times[fibonacci_method.__name__].append(duration)
        except:
            execution_times[fibonacci_method.__name__].append(None)

# Plotting
plt.figure(figsize=(10, 6))
for method_name, times in execution_times.items():
    plt.plot(sample_indices, times, label=method_name)
plt.xlabel('n')
plt.ylabel('Time (seconds)')
plt.title('Fibonacci Computation Times')
plt.yscale('log')
plt.legend()
plt.show()
