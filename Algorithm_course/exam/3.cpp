/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @Date: 2019-05-22 16:03:15
 * @LastEditors: Suwen SP\n
 * @LastEditTime: 2019-05-22 16:29:33
 */
#include <iostream>
using namespace std;
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

int midfind(int s[], int x, int length)
{
    selectionSort(s,length);
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        if (x < s[(left + right) / 2])
        {
            right = (left + right) / 2 - 1;
        }
        else if (x > s[(left + right) / 2])
        {
            left = (left + right) / 2 + 1;
        }
        else
        {
            return (left + right) / 2;
        }
    }
    return -1;
}
int main()
{
    int arr[9] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    cout << midfind(arr, 2, 9) << endl;
    return 0;
}