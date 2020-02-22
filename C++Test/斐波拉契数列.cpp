#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    int a = 1, b = 1, c, i = 27;
    cout << setw(8) << a << setw(8) << b;
    for (; i >= 0; i--)
    {
        c = a + b;
        cout << setw(8) << c;
        if (i % 6 == 0)
            cout << endl;
        b = a;
        a = c;
    }
    return 0;
}