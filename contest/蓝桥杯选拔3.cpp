/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen \n
 * @Date: 2018-12-22 09:52:30
 * @LastEditors: Suwen \n
 * @LastEditTime: 2018-12-22 09:54:17
 */
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main()
{
	char code[10000];
	memset(code, '\0', sizeof(code));       // 注意要初始化
	char codetmp[10000];
	memset(codetmp, '\0', sizeof(codetmp)); // 注意要初始化

	int index = 0;
	int n;
	cin >> code;
	int len = strlen(code);
	cin >> n;
	char start;
	int num = 0;
	while (n--)       // 这个while循环针对code数组
	{
		bool flag = 0;
		start = code[0];    // 标记当前连续的那个字符

		index = 0;   num = 0;
		len = strlen(code);

		for (int i = 0; i<len; i++)
		{
 			if (code[i]==start)    // 如果 当前字符==当前连续字符
				num++;
			if (i == len-1)        // 如果已经是最后一个字符了
				flag = 1;
			if (code[i]!=start)
			{
				/* 先把个数num和字符start存起来 */
				codetmp[index++] = num + '0';   // codetmp是字符数组，所以要加上'0'
				codetmp[index++] = start;
				/* 再把当前连续字符换成code[i] */
				start = code[i];
				num = 1;
			}
		}
		if (flag) // 如果已经是最后一个字符，因为我们还没有存num和start，得操作如下
		{
			codetmp[index++] = num + '0';
			codetmp[index++] = start;
		}

         /* 因为要保证while循环针对code数组，这里把codetmp数组复制到code数组 */
		int t_len = strlen(codetmp);
		for (int i = 0; i<t_len; i++)
			code[i] = codetmp[i];
	}
	cout << code << endl;
}
