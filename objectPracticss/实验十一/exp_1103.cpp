#include <iostream>
using namespace std;
int main()
{
    int a = 120, b = 250;
    double x = 256.431, y = 130.125;
    cout.setf(ios::dec | ios::showpos);
    cout << a << " " << b << endl;
    cout.setf(ios::dec | ios::showbase);
    cout << a << " " << b << endl;
    cout.setf(ios::dec | ios::fixed);
    cout << x << " " << y << endl;
    cout.setf(ios::dec | ios::scientific);
    cout << x << " " << y << endl;
    cout.setf(ios::dec | ios::showpos);
    cout << x << " " << y << endl;
    return 0;
}