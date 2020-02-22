#include <iostream>
using namespace std;
int main()
{
    while (1)
    {
        int num = 0;
        char ch;
        for (int i = 0;; i++)
        {
            ch = getchar();
            if (ch == '\n' || ch == '#')
                break;
            if (ch != ' ')
                num += (i + 1) * (int(ch) - 64);
        }
        if (ch == '#')
            break;
        else
            cout << num << endl;
    }
    return 0;
}
