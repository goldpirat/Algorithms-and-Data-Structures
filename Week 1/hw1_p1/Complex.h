/*
	CH-231-A
	hw1_p1.cpp
	Flori Kusari
	fkusari@jacobs-university.de
*/
#include <string>

class Complex {
    private:
        int real;
        int imaginary;
    public:
        // Parametrized Constructor
        Complex(int real, int complex);
        // Default Constructor
        Complex();
        // Copy constructor
        Complex(Complex& num);
        // Destructor
        ~Complex();

        // Setters
        void setReal(int newReal);
        void setImaginary(int newImaginary);

        // Getterss
        int getReal();
        int getImaginary();

        // Overloaded friend functions
        friend std::ostream& operator<<(std::ostream &out, const Complex &c);
        friend std::istream& operator>>(std::istream& in, Complex &c);

        // Overloaded addition, subtraction and multiplication operators
        Complex operator+(const Complex& secondComplex);
        Complex operator-(const Complex& secondComplex);
        Complex operator*(const Complex& secondComplex);

        // Overloaded assignment operator for Complex instances
        Complex& operator=(const Complex obj);

        // Overloaded equality operator for Complex instance
        bool operator==(const Complex& obj);

        void print();
};