#	CH-231-A
#	plotter.py
#	Flori Kusari
#	fkusari@jacobs-university.de

import matplotlib as plt

# Function to read data from a file and return as two lists
def read_data(filename):
    x = []
    y = []
    with open(filename, 'r') as file:
        for line in file:
            values = line.split()
            x.append(int(values[0]))
            y.append(float(values[1]))
    return x, y

# Read data from output files``
worst_x, worst_y = read_data('worstCaseData.txt')
average_x, average_y = read_data('averageCaseData.txt')
best_x, best_y = read_data('bestCaseData.txt')

# Plotting
plt.plot(worst_x, worst_y, label='Worst Case')
plt.plot(average_x, average_y, label='Average Case')
plt.plot(best_x, best_y, label='Best Case')

plt.xlabel('Size of Input (n)')
plt.ylabel('Time (s)')
plt.title('Selection Sort Performance')
plt.legend()

plt.grid(True)
plt.show()
