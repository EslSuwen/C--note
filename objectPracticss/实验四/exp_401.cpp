//程序1 (exp_401.CPP)
#include <iostream>
using namespace std;
class Base
{
  private:
    float x,
        y;

  public:
    Base(float a = 0, float b = 0)
    {
        x = a;
        y = b;
    }
    void print(void)
    {
        cout << "x=" << x << "  y=" << y << endl;
    }
};