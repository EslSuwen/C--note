/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2018-11-24 20:17:35
 * @LastEditTime: 2019-03-17 09:08:10
 */
#include <iostream>
using namespace std;
int main()
{
    cout << "hello world!" << endl;
    cout << "感受vscode的香甜气息！" << endl;
    int(*s)[1000] = new int[1000][1000]();
    char *str = new char[10]();
    char *str1 = new char[10];
    cout << int(str[4]) << endl;
    cout << int(str1[4]) << endl;
    cout << int(NULL) << endl;
    // cout << s[555][555] << endl;
    cout << s << endl;
    getchar();
    return 0;
}