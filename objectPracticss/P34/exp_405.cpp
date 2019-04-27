#include <iostream>
#include "Circle.h"
using namespace std;
int main()
{
    Circle c1(1,2,3) ;
    cout << c1.computArea() << endl;
    cout << c1.computPerimeter() << endl;
    cout << c1.getX()<<" "<<c1.getY()<< " " <<c1.getRadius()<< endl;
    getchar();
    return 0;
}