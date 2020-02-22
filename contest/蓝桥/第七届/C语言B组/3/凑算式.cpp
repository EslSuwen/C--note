/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-17 09:13:21
 * @LastEditTime: 2019-03-17 09:34:43
 */
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    double a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int res = 0;
    do
    {
        if (a[0] + a[1] / a[2] + (a[3] * 100 + a[4] * 10 + a[5]) / (a[6] * 100 + a[7] * 10 + a[8]) == 10.0)
            res++;
        cout << a << endl;
    } while (next_permutation(a, a + 9));
    cout << res << endl;
    return 0;
}