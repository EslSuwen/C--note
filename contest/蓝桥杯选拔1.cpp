/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen \n
 * @Date: 2018-12-22 09:16:55
 * @LastEditors: Suwen \n
 * @LastEditTime: 2018-12-22 09:17:09
 */
#include<iostream>
using namespace std;
int main()
{
    int a,b,sum,array[3],max=0;
    cin>>a>>b;
    sum=a+b;
    array[0]=sum+a-1;
    array[1]=sum+b-1;
    array[2]=sum-1;
    for(int i=0;i<3;i++)
    {
        if(array[i]%a==0||array[i]%b==0)
            array[i]=0;
        if(array[i]>max)
            max=array[i];
    }
    cout << max << endl;
    return 0;
}