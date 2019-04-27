/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-08 20:29:38
 * @LastEditTime: 2019-03-08 20:39:59
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool test(char *s, char *p)
{
    for (int i = 0; i < 9; i++)
    {
        if (s[i] == p[i])
            continue;
        if (s[i] == '0')
            continue;
        return 0;
    }
    return 1;
}
char *IntToString(int n)
{
    char *p = (char *)malloc(10 * sizeof(char));
    itoa(n, p, 10);
    return p;
}
int main()
{
    int i, j, num = 0;
    char s[10];
    for (i = 0; i < 9; i++)
    {
        int a;
        scanf("%d", &a);
        s[i] = '0' + a;
    }
    char *p0 = IntToString(492357816);
    char *p1 = IntToString(834159672);
    char *p2 = IntToString(618753294);
    char *p3 = IntToString(276951438);
    char *p4 = IntToString(294753618);
    char *p5 = IntToString(438951276);
    char *p6 = IntToString(816357492);
    char *p7 = IntToString(672159834);
    char *pp[8] = {p0, p1, p2, p3, p4, p5, p6, p7};
    for (i = 0; i < 8; i++)
    {
        if (test(s, pp[i]))
        {
            for (j = 0; j < 9; j++)
            {
                printf("%c ", pp[i][j]);
                if ((j + 1) % 3 == 0)
                    printf("\n");
            }
        }
    }
    for (i = 0; i < 8; i++)
    {
        if (pp[i] != NULL)
            free(pp[i]);
    }
    return 0;
}