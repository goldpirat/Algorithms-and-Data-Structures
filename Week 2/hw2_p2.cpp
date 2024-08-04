/*
	CH-231-A
	hw2_p2.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/
#include <iostream>
#include <deque>

using namespace std;

int main() {
	// Create deque made of floats
	deque<float> A;
	float temp;

	// Read floats until inputted value is 0
	cin >> temp;
	while (temp != 0) {
		// Store them in the back or the front according to their sign
		if (temp > 0)
			A.push_back(temp);
		else A.push_front(temp);
		cin >> temp;
	}

	// Output deque to stdout
	for (deque<float>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			cout << *it;
		else cout << " " << *it;
	}

	// output newline to stdout
	cout << endl;
    cout << endl;

	// Iterate through the deque until finding a positive float and insert a 0
	// in that position in the deque
	for (deque<float>::iterator it = A.begin(); it != A.end(); it++) {
		if (*it > 0) {
			A.insert(it, 0);
			break;
		}
	}

	// Output deque to stdout after insertion
	for (deque<float>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			cout << *it;
		else cout << ";" << *it;
	}

	cout << endl;

	return 0;
}