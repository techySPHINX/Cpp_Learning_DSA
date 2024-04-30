#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Complex
{
    int a, b;

public:
    void setNumber(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    friend Complex sumComplex(Complex o1, Complex o2);

    void printNumber()
    {
        cout << "Your complex number is " << a << "i + " << b << endl;
    }
};

Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main()
{
    Complex c1, c2, sum;
    c1.setNumber(3, 4);
    c2.setNumber(5, 8);
    sum = sumComplex(c1, c2);
    sum.printNumber();
    return 0;
}

//friend functions means it allows to use private parts of main class for non member functions
//usually contains the arguments as objects
//can be declared inside private or public section of the class