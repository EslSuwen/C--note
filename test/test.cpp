/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen \n
 * @Date: 2018-11-25 00:22:19
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2019-01-21 14:13:25
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "hello world" << endl;
    string a;
    int n;
    cin >> n;
    char t[2];
    for (int i = 1; i <= n; i++)
    {

        t[0] = i;
    }
    cout << t[0] << endl;
    return 0;
}