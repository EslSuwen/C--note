/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen \n
 * @LastEditors: Suwen \n
 * @Date: 2019-03-02 20:36:31
 * @LastEditTime: 2019-03-02 21:03:26
 */
#include <iostream>
using namespace std;
int main()
{
    int a[10];
    int *b = new int[10]();
    a[10] = 10;
    b[111] = 10;
    cout << b[111] << endl;
    return 0;
}