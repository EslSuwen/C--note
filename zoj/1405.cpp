#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    char *str=new char[20]() ;
    int n;
    while (1)
    {
        int i = 0, sum = 0;
        cin >> n;
        char ch;
        ch = getchar();
        for (int j = 0; j < n; j++)
        {
            if (str[j] == ch)
                i++;
        }
        str[i] = ch;
    }
    return 0;
}