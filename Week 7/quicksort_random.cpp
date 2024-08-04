/*
	CH-231-A
	hw7_p2.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/

#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int,int> partition(int *arr, int begin, int end) {  
    int size = end - begin;

    //generate a random index and then swap it with elem in first position
    int random_IND = rand() % size + begin;
    swap(arr[begin], arr[random_IND]);

    //generate a random index and then swap it with elem in second position
    random_IND = rand() % size + begin;
    swap(arr[begin+1], arr[random_IND]);

    //order the pivots
    if (arr[begin] > arr[begin+1]) {
        swap(arr[begin], arr[begin+1]);
    }
    swap(arr[begin+1], arr[end-1]);

    //continue like in quicksort_modified
    int i = begin;
    for (int k = begin+1; k < end-1; k++) {
        if (arr[k] < arr[begin]) {
            i++;
            swap(arr[k], arr[i]);
        }
    }
    swap(arr[begin], arr[i]);

    int j = end-1;
    for (int k = end-2; k > i; k--) {
        if (arr[k] > arr[end-1]) {
            j--;
            swap(arr[k], arr[j]);
        }
    }
    swap(arr[end-1], arr[j]);

    return {i,j};
}

void quicksort(int *arr, int begin, int end) {
    if (begin < end-1) {
        //get the indices of pivots
        tuple<int,int> pivots = partition(arr, begin, end);

        //recursively sort the other parts of the array excluding the pivots
        quicksort(arr, begin, get<0>(pivots));
        quicksort(arr, get<0>(pivots)+1, get<1>(pivots));
        quicksort(arr, get<1>(pivots)+1, end); 
    }
}

int main() {
    srand(time(0));
    int test_cases = 10;    //set the number of test cases
    int size = 10;  //set the size of the arrays

    cout << "Quicksort with two random pivots: " << endl;
    for (int i = 0; i < test_cases; i++) {

        int *arr = new int[size];

        //generate random elems for the arrays
        for (int i = 0; i < size; i++) {
            int elem = rand() % 50;
            arr[i] = elem;
        }

        cout << "Unsorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        quicksort(arr, 0, size);

        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << endl;

        delete [] arr;
    }
    
    return 0;
}