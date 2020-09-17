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
    int a,b,t,i=0;
    cin>>a>>b;
    while(cin >> t)
    {
        i++;
        if(i==b) continue;
        cout<<t<<" ";
        if(i==a) break;
    }
    return 0;
}