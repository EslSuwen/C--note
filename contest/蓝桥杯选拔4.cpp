/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen \n
 * @Date: 2018-12-22 09:57:10
 * @LastEditors: Suwen \n
 * @LastEditTime: 2018-12-22 09:58:10
 */
#include <stdio.h>
#include <string.h>
int main()
{
    char a[1001];
    int i, j, b, flag = 0, res;
    scanf("%s", a);
    b = strlen(a);
    if (b == 2)
    {
        if (a[0] - '0' + 1 == a[1] - '0')
            res = a[1] - '0' + 1;
        else
            res = a[0] - '0' + 1;
    }
    else if (b == 3)
    {
        if (a[0] - '0' + 1 == a[1] - '0' && a[1] - '0' + 1 == a[2] - '0')
            res = a[2] - '0' + 1;
        else if (a[0] == '9' && a[1] == '1' && a[2] == '0')
            res = 11;
        else if (a[0] == '9' && a[1] == '1' && a[2] == '1')
            res = 10;
        else
        {
            if (a[0] - '0' + 2 == a[1] - '0')
                res = a[0] - '0' + 1;
            else if (a[1] - '0' + 2 == a[2] - '0')
                res = a[1] - '0' + 1;
            else if (a[0] == '8' && a[1] == '1')
                res = 9;
        }
    }
    else
    {
        j = -1; //123456
        if (((a[0] - '0' + 1 == a[1] - '0' || a[0] - '0' + 2 == a[1] - '0') && (a[1] - '0' + 1 == a[2] - '0' || a[1] - '0' + 2 == a[2] - '0')) || (a[0] == '8' && a[1] == '9') || a[0] == '9' || a[0] == '8')
        {
            for (i = 0; i < b; i++)
            {
                if (flag)
                    break;
                if (a[i] + 1 == a[i + 1] && a[i] != '9')
                {
                    j = i + 2;
                    continue;
                }
                else if (a[i] == '8')
                {
                    if (a[i + 1] == '9' && i + 1 == b - 1)
                    {
                        flag = 1;
                        res = 10;
                    }
                    if (a[i + 1] == '1' && a[i + 2] == '0')
                    {
                        flag = 1;
                        res = 9;
                    }
                }
                else if (a[i] == '9')
                {
                    if (i == b - 3)
                    {
                        if (a[b - 1] == '1')
                        {
                            flag = 1;
                            res = 10;
                        }
                        if (a[b - 1] == '0')
                        {
                            flag = 1;
                            res = 11;
                        }
                    }
                    else if (i < b - 2)
                    {
                        if (a[i + 1] == '1' && a[i + 2] == '0')
                            break;
                        else if (a[i + 1] == '1' && a[i + 2] == '1')
                        {
                            flag = 1;
                            res = 10;
                        }
                    }
                    else if (i == b - 1 && flag == 0)
                    {
                        flag = 1;
                        res = 10;
                    }
                    break;
                }
                else if (a[i] - '0' + 2 == a[i + 1] - '0')
                {
                    flag = 1;
                    res = a[i] - '0' + 1;
                }
            }
        }
        //101112
        if (flag == 0)
        {
            int x[105], o = 0;
            if (j == -1)
                j = 0;
            if (j == b)
            {
                res = a[b - 1] - '0' + 1;
                flag = 1;
            }
            for (i = j; i < b; i += 2)
            {
                x[o++] = (a[i] - '0') * 10 + (a[i + 1] - '0');
            }
            for (i = 0; i < o; i++)
            {
                //printf("%d**\n",x[i]);
                if (x[i] + 1 == x[i + 1])
                    continue;
                else if (x[i] + 2 == x[i + 1])
                {
                    flag = 1;
                    res = x[i] + 1;
                    break;
                }
            }
            if (flag == 0)
                res = x[o - 1] + 1;
        }
    }
    printf("%d\n", res);
}
