/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen \n
 * @Date: 2018-12-22 09:23:38
 * @LastEditors: Suwen \n
 * @LastEditTime: 2018-12-22 09:45:56
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int n;
    while (cin >> n)
    {
        if (n == -1)
            break;
        cin >> str;
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == str[i + 1])
            {
                for (int j = i; j < len; j++)
                {
                    str[j] = str[j + 1];
                }
                len--;
                i--;
            }
        }
        for (int i = 0; i < len; i++)
        {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}