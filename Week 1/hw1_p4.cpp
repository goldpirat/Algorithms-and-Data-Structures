/*
	CH-231-A
	hw1_p4.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	string temp;
	vector<string> wordVector;
	cin >> temp;

	// Push back each word into vector each word until END is inputted
	while (temp.compare("END") != 0) {
		wordVector.push_back(temp);
		cin >> temp;
	}

	// Loop through the vector and output the words using index operator
	if (!wordVector.empty())
		for (unsigned int i = 0; i < wordVector.size(); i++) {
			// Group the separator before the element when index is not 0
			// Although not needed in case of " "
			if (i == 0)
				cout << wordVector[i];
			else cout << " " << wordVector[i];
		}
	cout << endl;

	// Set a mark variable at the beginning of the vector
	vector<string>::iterator begin = wordVector.begin();

	// Iterate through the vector using iterator and output using dereferencing
	if (!wordVector.empty())
		for (vector<string>::iterator it = wordVector.begin();
				it != wordVector.end(); it++) {
			// Group the separator before the element when index is not 0
			if (it == begin)
				cout << *it;
			else cout << "," << *it;
		}
	cout << endl;
	
	return 0;
}
