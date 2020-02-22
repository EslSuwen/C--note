/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-27 23:17:48
 * @LastEditTime: 2019-05-08 22:54:02
 */
#include <iostream>
#include <set>

using namespace std;
int main()
{
    int *a = new int[5]{1, 2, 3, 4, 5};
    auto arr = {1, 2, 3, 4, 5};
    int arr1[3] = {1, 2, 3};
    for (auto i : arr1)
    {
        cout << i << endl;
    }
    return 0;
}