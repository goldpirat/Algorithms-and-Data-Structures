/*
	CH-231-A
	hw5_p1.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

// Function to compute the nth Fibonacci number using a simple recursive approach
int simple_recursive_fibonacci(int n) {
    if (n <= 1) return n;
    return simple_recursive_fibonacci(n - 1) + simple_recursive_fibonacci(n - 2);
}

// Function to compute the nth Fibonacci number using a dynamic programming approach
int dynamic_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// Function to compute the nth Fibonacci number using Binet's formula
int binet_formula(int n) {
    const double sqrt5 = sqrt(5);
    const double phi = (1 + sqrt5) / 2;
    return static_cast<int>(round(pow(phi, n) / sqrt5));
}

// Helper function to perform matrix multiplication
void matrix_multiply(int mat1[2][2], int mat2[2][2]) {
    int x =  mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    int y =  mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    int z =  mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    int w =  mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}

// Function to compute power of a matrix
void matrix_power(int mat[2][2], int n) {
    if (n <= 1) return;

    int base[2][2] = {{1, 1}, {1, 0}};
    matrix_power(mat, n / 2);
    matrix_multiply(mat, mat);

    if (n % 2 != 0) matrix_multiply(mat, base);
}

// Function to compute the nth Fibonacci number using the matrix exponentiation method
int matrix_fibonacci(int n) {
    if (n == 0) return 0;

    int mat[2][2] = {{1, 1}, {1, 0}};
    matrix_power(mat, n - 1);
    return mat[0][0];
}

int main() {
    int limit = 30; // Adjust the limit for benchmarking

    ofstream resultsFile("benchmark_results.txt");

    cout << "Benchmarking various Fibonacci computation methods..." << endl;

    // Benchmark naive recursion
    for (int i = 0; i < limit; i++) {
        auto start = high_resolution_clock::now();
        simple_recursive_fibonacci(i);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        resultsFile << "Naive Recursion, n=" << i << ": " << duration << " microseconds" << endl;
    }

    // Benchmark dynamic programming approach
    for (int i = 0; i < limit; i++) {
        auto start = high_resolution_clock::now();
        dynamic_fibonacci(i);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        resultsFile << "Dynamic Programming, n=" << i << ": " << duration << " microseconds" << endl;
    }

    // Benchmark Binet's formula
    for (int i = 0; i < limit; i++) {
        auto start = high_resolution_clock::now();
        binet_formula(i);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        resultsFile << "Binet's Formula, n=" << i << ": " << duration << " microseconds" << endl;
    }

    // Benchmark matrix exponentiation method
    for (int i = 0; i < limit; i++) {
        auto start = high_resolution_clock::now();
        matrix_fibonacci(i);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        resultsFile << "Matrix Exponentiation, n=" << i << ": " << duration << " microseconds" << endl;
    }

    resultsFile.close();
    cout << "Benchmarking complete. Results saved to benchmark_results.txt." << endl;

    return 0;
}
