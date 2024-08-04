/*
	CH-231-A
	hw2_p4.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;

	// Push integer values from 1 to 30
	for (int i = 1; i < 31; i++)
		arr.push_back(i);
	arr.push_back(5); // Push 5 at the end of the vector

	// Reverse the order of the integers in the vector
	reverse(arr.begin(), arr.end());

	// Iterate through the vector and print each integer
	for (vector<int>::iterator it = arr.begin(); it != arr.end();
		 it++) {
		if (it == arr.begin())
			cout << *it;
		else cout << " " << *it;
	}
	cout << endl;

	// Replace every instance of the integer 5 with 129 in the vector
	replace(arr.begin(), arr.end(), 5, 129);

	// Iterate through the vector and print each integer
	for (vector<int>::iterator it = arr.begin(); it != arr.end();
		 it++) {
		if (it == arr.begin())
			cout << *it;
		else cout << " " << *it;
	}
	cout << endl;

	return 0;
}