/*
	CH-231-A
	hw2_p5.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/
#include <iostream>
#include <set>
#include <cstdlib> //For srand
#include <cstddef> //For NULL
#include <ctime> // for time


using namespace std;

int main() {
	// Set is the suitable container
	int temp;
	set<int> rands;
	set<int>::iterator it;

	// Initializing random number generator
	srand(time(NULL));

	// Produce random numbers until 6 unique ones show up and insert them into
	// the set
	while (rands.size() != 6) {
		temp = rand() % 49 + 1;
		rands.insert(temp);
	}

	// Iterate through the set and output each integer into stdout
	for (it = rands.begin(); it != rands.end(); it++) {
		if (it == rands.begin())
			cout << *it;
		else cout << " " << *it;
	}
	cout << endl;

	return 0;
}