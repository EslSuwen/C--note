/*
 * @Author: Suwen
 * @Description:
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-08 19:41:02
 * @LastEditTime: 2019-03-08 20:23:16
 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char c[100];
    int cnt = 0;
    while (n)
    {
        if (n % 26 == 0)
        {
            c[cnt++] = 26 + 64;
            n /= 26;
            n--;
        }
        else
        {
            c[cnt++] = n % 26 + 64;
            n /= 26;
        }
    }
    for (int i = cnt - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}