#include "user_date.h"

int main()
{
    date d1(1998, 9, 29), d2(1998, 8, 24), d3(2007, 7, 31), d4(2017, 6, 8);
    cout << (d1 > d2) << endl;
    cout << (d1 < d2) << endl;
    cout << (d1 == d2) << endl;
    cout << (d1 == d1) << endl;
    cout << (d2 >= d2) << endl;
    cout << (d3 <= d4) << endl;
    //cout << (d4 - d1) << endl;
    return 0;
}