#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int ch = 97;
    char str[] = "student";
    cout.put(ch) << endl;
    cout << char(ch) << endl;
    cout.write(str, strlen(str));
    return 0;
}