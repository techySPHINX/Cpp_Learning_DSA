#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Forward declaration
class Complex; // so that compiler would not get confuse

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};

class Complex
{
    int a, b;
    // friend int Calculator ::sumRealComplex(Complex o1, Complex o2); // scope resolution operator
    // friend int Calculator ::sumCompComplex(Complex o1, Complex o2);

    //Aliter:
    friend class Calculator;

public:
    void setNumber(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    void printNumber()
    {
        cout << "Your complex number is " << a << "i + " << b << endl;
    }
};

int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}
int main()
{
    Complex c1, c2;
    c1.setNumber(3, 4);
    c2.setNumber(5, 8);
    c1.printNumber();
    c2.printNumber();
    Calculator calc;
    int res = calc.sumRealComplex(c1, c2);
    cout << "The sum of real part of c1 and c2 is " << res << endl;
    return 0;
}

// if we need to make more functions as friend then it woud be goofd to make friiend class which conatin all friend functions
