/*
	CH-231-A
	hw4_p1.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace chrono;


void insertionSort(vector<int> vec, vector<int>::iterator begin, 
                   vector<int>::iterator end) {

    for (auto j = begin+1; j < end; j++) {
        int key = *j;

        int beginIND = distance(vec.begin(), begin)-1; //get index of begin
        int jIND = distance(vec.begin(), j);    //get index of j
        int i = jIND - 1;

        while ((i > beginIND) && (vec[i] > key)) {
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    } 
}

void merge(vector<int> vec, vector<int>::iterator begin, 
           vector<int>::iterator middle, vector<int>::iterator end) {

    vector<int> left;
    left.assign(begin, middle); //assign the elements of the first half
    left.push_back(numeric_limits<int>::max()); //set last element to max int

    vector<int> right;
    right.assign(middle, end);  //assign the elements of the second half
    right.push_back(numeric_limits<int>::max()); //set last element to max int
    
    int leftIND = 0, rightIND = 0;
    for (auto it = begin; it < end; it++) {
        if (left[leftIND] <= right[rightIND]) {
            *it = left[leftIND];
            leftIND++;
        }
        else {
            *it = right[rightIND];
            rightIND++;
        }
    }
}

void mergeInsertionSort(const vector<int> &vec, vector<int>::iterator begin, 
               vector<int>::iterator end, int k) {

    int size = distance(begin, end); //get size of vector in current iteration
    if (size <= k) {    //check if we've reached k-sized vectors yet
        insertionSort(vec, begin, end);
    }
    else {
        auto middle = begin + (end - begin) / 2;    //find middle of vector
        mergeInsertionSort(vec, begin, middle, k);  //first half
        mergeInsertionSort(vec, middle, end, k);    //second half
        merge(vec, begin, middle, end);             //merge the two halves
    }
}

vector<int> bestCase(int size) {
    vector<int> vec;

    int elem = rand() % 50;     //generate first element 0-50
    vec.push_back(elem);        //add it to the vector

    for (int i = 1; i < size; i++) {    //start from second spot
        int increment = 1 + rand() % 10;    //generate a random increment
        elem += increment;      //add increment to previous elem
        vec.push_back(elem);    //add element to the back
    }

    return vec;
}

vector<int> worstCase(int size) {
    vector<int> vec;

    int elem = rand() % 50;     //generate first element 0-50
    vec.push_back(elem);        //add it to the vector

    for (int i = 1; i < size; i++) {    //start from second spot
        int increment = 1 + rand() % 10;    //generate a random increment
        elem += increment;      //add increment to previous elem
        vec.push_back(elem);    //add element to the back
    }

    reverse(vec.begin(), vec.end());    //reverse vector to get worse

    return vec;
}

vector<int> averageCase(int size) {
    vector<int> vec;

    for (int i = 0; i < size; i++) {
        int elem = rand() % 50;     //generate random number
        vec.push_back(elem);        //add it to the vector
    }

    return vec;
}

int main () {
    //vectors that will hold compuation times for the different k-values
    vector<int> bestCaseTimes;
    vector<int> worstCaseTimes;
    vector<int> averageCaseTimes;

    int kValue = 100;   //set max k-value
    for (int i = 2; i < kValue; i++) {  //iterate from 2 to max k-value
        vector<int> vec = bestCase(100);

        //compute the time of the algorithm in microseconds
        auto start = high_resolution_clock::now(); 
        mergeInsertionSort(vec, vec.begin(), vec.end(), i);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        bestCaseTimes.push_back(duration.count());  //add time to time vector
    }

    for (int i = 2; i < kValue; i++) {  //iterate from 2 to max k-value
        vector<int> vec = worstCase(100);

        //compute the time of the algorithm in microseconds
        auto start = high_resolution_clock::now(); 
        mergeInsertionSort(vec, vec.begin(), vec.end(), i);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        worstCaseTimes.push_back(duration.count()); //add time to time vector
    }

    for (int i = 2; i < kValue; i++) { //iterate from 2 to max k-value
        vector<int> vec = averageCase(100);

        //compute the time of the algorithm in microseconds
        auto start = high_resolution_clock::now(); 
        mergeInsertionSort(vec, vec.begin(), vec.end(), i);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        averageCaseTimes.push_back(duration.count());   //add time to time vector
    }

    //print out the times
    cout << "Times for Best Case: ";
    for (auto elem : bestCaseTimes) {
        cout << elem << ", ";
    }
    cout << endl << endl;

    cout << "Times for Worst Case: ";
    for (auto elem : worstCaseTimes) {
        cout << elem << ", ";
    }
    cout << endl << endl;

    cout << "Times for Average Case: ";
    for (auto elem : averageCaseTimes) {
        cout << elem << ", ";
    }
    cout << endl << endl;

    return 0;
}