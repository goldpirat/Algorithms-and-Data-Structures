CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11

all: sort plot

sort: hw4_p1.cpp
	$(CC) $(CFLAGS) -o sort hw4_p1.cpp

plot:
	python3 hw4_p1.py

clean:
	rm -f cc