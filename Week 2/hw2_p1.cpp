/*
	CH-231-A
	hw2_p1.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main() {
	fstream file("listB.txt", ios::out);
	list<int> A, B;
	int temp;
	cin >> temp;

    // Push ints into the back of A and the front of B if they are positive
	while (temp > 0) {
		A.push_back(temp);
		B.push_front(temp);
		cin >> temp;
	}

    // Output list A into stdout
	for (list<int>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			cout << *it;
		else cout << " " << *it;
	}

    // Output list B into listB.txt file
	if (file.good() && file.is_open()) {
		for (list<int>::iterator it = B.begin(); it != B.end(); it++) {
			if (it == B.begin())
                file << *it;
			else file << " " << *it;
		}
	} else cout << "Error while opening file!" << endl;

	file.close();

    // Output newline in stdout
    cout << endl;

    // Pop element from the front of A and push it in the back of A
    temp = *A.begin();
    A.push_back(temp);
    A.pop_front();

    // Pop element from the front of B and push it in the back of B
    temp = *B.begin();
    B.push_back(temp);
    B.pop_front();

    // Output list A into stdout
    for (list<int>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			cout << *it;
		else cout << "," << *it;
	}
    cout << endl;

    // Output list B into stdout
    for (list<int>::iterator it = B.begin(); it != B.end(); it++) {
		if (it == B.begin())
			cout << *it;
		else cout << "," << *it;
	}

    // Output newline in stdout
    cout << endl;

    // Merge list B into list A and sort A
    A.merge(B);
    A.sort();

    // Output the list A (now merged with B) into stdout
    for (list<int>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			cout << *it;
		else cout << " " << *it;
	}

	cout << endl;

	return 0;
}