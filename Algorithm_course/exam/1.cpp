/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @Date: 2019-05-22 16:12:50
 * @LastEditors: Suwen SP\n
 * @LastEditTime: 2019-05-22 16:15:21
 */
#include <iostream>
using namespace std;
//
int SequentialSearch(int a[], int lengh, int key)
{
    for (int i = 0; i < lengh; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[9] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    cout << SequentialSearch(arr, 5, 9) << endl;
    return 0;
}