'''
	CH-231-A
	hw6_p2.cpp
	Flori Kusari
	fkusari@jacobs-university.de
'''

import matplotlib.pyplot as plt
import pandas as pd

# Number of test cases and openning the file in read mode
testCases = 1000
file = open("times.txt", "r")

# Ignore first line
file.readline()
heap_sort = list(file.readline().split(" "))
del heap_sort[-1]
heap_sort = [int(x) for x in heap_sort]

df = pd.DataFrame({'y': heap_sort})
rolling_mean = df.rolling(window=10).mean()
heapSort_smooth = rolling_mean['y'].values


file.readline()
heap_sort_variant = list(file.readline().split(" "))
del heap_sort_variant[-1]
heap_sort_variant = [int(x) for x in heap_sort_variant]

df = pd.DataFrame({'y': heap_sort_variant})
rolling_mean = df.rolling(window=10).mean()
heapSortVariant_smooth = rolling_mean['y'].values

# Close File
file.close()

# Plotting
plt.plot(range(testCases), heapSort_smooth, label="Heap Sort", linewidth=2)
plt.plot(range(testCases), heapSortVariant_smooth, label="Heap Sort Variant", linewidth=2)

plt.xlabel("Size of Vector")
plt.ylabel("Time in Microseconds")
plt.title("Compuation Time")
plt.show()