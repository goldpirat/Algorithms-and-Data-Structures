/*
	CH-231-A
	hw6_p2.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

// Function to heapify a subtree rooted with node i which is an index in A[].
void max_heapify(vector<int> &A, int &heapSize, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if ((l < heapSize) && (A[l] > A[largest])) {
        largest = l;
    }
    if ((r < heapSize) && (A[r] > A[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, heapSize, largest);
    }
}

// Function to build a Max-Heap from the given array
void build_max_heap(vector<int> &A, int &heapSize) {
    for (int i = round(A.size()/2.0)-1; i >= 0; i--) {
        max_heapify(A, heapSize, i);
    }
}

// The float_down function is used in the variant of heap sort to adjust the position of the new root.
// This implementation floats the new root down to its correct position in the heap after the swap.
void float_down(vector<int> &A, int &heapSize, int i) {
    while (i*2 + 1 < heapSize) {
        int j = i*2 + 1;
        if ((j + 1 < heapSize) && (A[j] < A[j+1])) {
            j++;
        }
        if (A[i] < A[j]) {
            swap(A[i], A[j]);
            i = j;
        } 
        else {
            break;
        }
    }
}

// Implements heap sort using the variant that includes the float_down function.
void heap_sort(vector<int> &A) {
    int heapSize = A.size();
    build_max_heap(A, heapSize); 

    for (int i = A.size() - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        heapSize--;
        float_down(A, heapSize, 0);
    }
}

// Generates a vector of random integers of a specified size
vector<int> randomVec(int size) {
    vector<int> vec;

    for (int i = 0; i < size; i++) {
        int elem = rand() % 50;
        vec.push_back(elem);
    }

    return vec;
}

int main () {
    srand(time(0));

    int testCases = 1000;
    ofstream file("times.txt", ios::app);

    file << "Heap Sort Variant: " << endl;
    for (int i = 1; i <= testCases; i++) {
        vector<int> vec = randomVec(i);

        auto start = high_resolution_clock::now(); 
        heap_sort(vec);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        file << duration.count() << " ";
    } 

    file.close();

    return 0;
}