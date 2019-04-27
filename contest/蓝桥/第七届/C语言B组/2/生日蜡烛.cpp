/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-17 08:39:53
 * @LastEditTime: 2019-03-17 09:06:25
 */
#include <iostream>
using namespace std;
int main()
{
    int num = 236;
    for (int i = 1; i < 100; i++)
    {
        int s = 0;
        for (int j = i; s <= num; j++)
        {
            s += j;
            if (s == num)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    return 0;
}
/* #include <iostream>

using namespace std;

int main()
{
    int i, j, sum;
    for (i = 10; i < 100; i++)
    {
        sum = 0;
        for (j = i; j > 0; j--)
        {
            sum += j;
            if (sum == 236)
            {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }

    return 0;
} */