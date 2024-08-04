#	CH-231-A
#	hw4_p1.py
#	Flori Kusari
#	fkusari@jacobs-university.de

import matplotlib.pyplot as plt
import numpy as np

### Times here are for a fixed sized vector of 100 elements

#numpy array that holds Best Case time computations
bestCase = np.array([201, 120, 109, 108, 76, 64, 66, 63, 63, 64, 
                     52, 39, 39, 39, 39, 39, 39, 39, 39, 40, 40, 
                     39, 39, 54, 23, 24, 22, 23, 23, 23, 23, 23, 
                     23, 23, 22, 23, 23, 23, 23, 23, 23, 23, 23, 
                     23, 23, 23, 23, 23, 15, 15, 15, 15, 15, 15, 
                     15, 15, 45, 26, 28, 30, 17, 17, 16, 16, 19, 
                     28, 28, 31, 30, 29, 29, 31, 28, 30, 29, 31, 
                     37, 29, 28, 29, 28, 34, 31, 30, 29, 30, 29, 
                     31, 29, 30, 17, 17, 16, 16, 16, 16, 16, 16])

#numpy array that holds Worst Case time computations
worstCase = np.array([201, 124, 112, 148, 83, 70, 113, 113, 113, 118,
                      105, 86, 84, 90, 83, 85, 49, 48, 48, 48, 74, 81,
                      76, 72, 66, 73, 68, 40, 40, 40, 40, 40, 40, 41, 
                      40, 40, 42, 41, 40, 40, 41, 40, 41, 40, 40, 39, 
                      39, 39, 48, 50, 49, 48, 48, 48, 49, 48, 48, 49, 
                      48, 72, 49, 50, 48, 48, 53, 80, 49, 49, 48, 49, 
                      48, 72, 53, 98, 36, 36, 36, 37, 36, 36, 37, 36, 
                      37, 37, 56, 38, 38, 37, 37, 36, 36, 36, 37, 36, 
                      37, 36, 79, 37])

#numpy array that holds Average Case time computations
averageCase = np.array([221, 161, 133, 161, 99, 84, 93, 88, 87, 89, 
                        75, 62, 58, 59, 60, 72, 54, 33, 43, 51, 51, 
                        50, 50, 42, 41, 46, 27, 42, 46, 42, 43, 42, 
                        42, 41, 40, 44, 42, 60, 73, 41, 40, 41, 157, 
                        46, 46, 43, 46, 47, 47, 63, 63, 45, 93, 37, 
                        35, 23, 22, 22, 22, 21, 22, 23, 22, 22, 23, 
                        22, 36, 36, 37, 35, 77, 35, 38, 39, 40, 45, 
                        29, 25, 53, 23, 22, 23, 21, 22, 22, 21, 21, 
                        21, 21, 22, 21, 23, 23, 46, 20, 20, 20, 20 ])


#plot the three lines
plt.plot(bestCase, label="Best Case")
plt.plot(worstCase, label="Worst Case")
plt.plot(averageCase, label="Average Case")

#add some lables, a title, and a legend
plt.xlabel("K-Value")
plt.ylabel("Time in Microseconds")
plt.title("Compuation Time for N=100")
plt.legend()
plt.show()