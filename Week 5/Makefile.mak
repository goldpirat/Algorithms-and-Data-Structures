CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11

all: fib plot

fib: hw5_p1.cpp
	$(CC) $(CFLAGS) -o fib fibonacci.cpp
	./fib

plot: fib
	python3 computationTimes.py

clean:
	rm -f fib


