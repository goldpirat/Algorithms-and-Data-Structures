"""
CH-231-A
hw5_p1.cpp
Flori Kusari
fkusari@jacobs-university.de
"""


import matplotlib.pyplot as plt
import pandas as pd
from itertools import repeat

naive_fill = 960
nValues = range(1000)

file = open("benchmark_results.txt", mode="r")
data = file.readline()
naive = data.replace("\n", " ").split(" ")
del naive[-1]
del naive[-1]
naive = [int(x) for x in naive]
naive = [None if x==-1 else x for x in naive]
naive = naive + list(repeat(None, naive_fill))

data = file.readline()
bottomUp = data.replace("\n", " ").split(" ")
del bottomUp[-1]
del bottomUp[-1]
bottomUp = [int(x) for x in bottomUp]
bottomUp = [None if x==-1 else x for x in bottomUp]

data = file.readline()
closedForm = data.replace("\n", " ").split(" ")
del closedForm[-1]
del closedForm[-1]
closedForm = [int(x) for x in closedForm]
closedForm = [None if x==-1 else x for x in closedForm]


data = file.readline()
matrixRepresentation = data.replace("\n", " ").split(" ")
del matrixRepresentation[-1]
del matrixRepresentation[-1]
matrixRepresentation = [int(x) for x in matrixRepresentation]
matrixRepresentation = [None if x==-1 else x for x in matrixRepresentation]

excel = pd.DataFrame([naive, bottomUp, closedForm, matrixRepresentation],
                     index=["Naive", "Bottom Up", "Closed Form", "Matrix Representation"],
                     columns=nValues)
excel.to_excel("Time_Computations.xlsx")

df = pd.DataFrame({'y': bottomUp})
rolling_mean = df.rolling(window=10).mean()
bottomUp_smooth = rolling_mean['y'].values


df = pd.DataFrame({'y': closedForm})
rolling_mean = df.rolling(window=10).mean()
closedForm_smooth = rolling_mean['y'].values

df = pd.DataFrame({'y': matrixRepresentation})
rolling_mean = df.rolling(window=10).mean()
matrixRepresentation_smooth = rolling_mean['y'].values

plt.plot(nValues, naive, label="Naive Recrusion", linewidth=2)
plt.plot(nValues, bottomUp_smooth, label="Bottom Up Method", linewidth=2)
plt.plot(nValues, closedForm_smooth, label="Closed Form Method", linewidth=2)
plt.plot(nValues, matrixRepresentation_smooth,
         label="Matrix Representation Method", linewidth=2)

#add some lables, a title, and a legend
plt.xlabel("Value of N")
plt.ylabel("Time in Microseconds")
plt.title("Compuation Time")
plt.legend(prop={'size':8})
plt.show()
