/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-28 12:24:52
 * @LastEditTime: 2019-03-28 12:36:03
 */
#include <iostream>
#include <stdio.h>
using namespace std;
void fun(int *a, int *b)
{
    int *c;
    c = a;
    a = b;
    b = c;
}
int main(int argc, char const *argv[])
{
    int x = 3, y = 5, *p = &x, *q = &y;
    fun(p, q);
    printf("%d,%d\n", *p, *q);
    printf("%d,%d\n", x, y);
    fun(&x, &y);
    printf("%d,%d\n", *p, *q);
    printf("%d,%d\n", x, y);
    return 0;
}
