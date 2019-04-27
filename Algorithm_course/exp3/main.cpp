/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-03 18:46:08
 * @LastEditTime: 2019-04-04 08:21:07
 */
#include "ListQueue.h"
#include "SeqQueue.h"
#include "SparseMatrix.h"
#include "StringMatch.h"

int main()
{
    {
        //队列测试
        SeqQueue<int> test1(10);
        for (int i = 0; i < 5; i++)
        {
            test1.EnQueue(i);
        }
        for (int i = 0; i < 5; i++)
        {
            int temp = 0;
            test1.DeQueue(temp);
            cout << temp << endl;
        }
    }

    { //链队列测试
        ListQueue<int> test2;

        for (int i = 0; i < 5; i++)
        {
            test2.EnQueue(i);
        }
        test2.travesal();
        for (int i = 0; i < 2; i++)
        {
            int temp = 0;
            test2.DeQueue(temp);
            cout << temp << endl;
        }
    }
    { //稀疏矩阵的转置}
        SparseMatrix<int> test3, test33, test333;
        cin >> test3;
        cout << test3;
        test33 = test3.Transpos();
        cout << "test33:" << test33;
        test333 = test3.FastTranspos();
        cout << "test333:" << test333;
    }

    { //模式匹配测试
        char str[100] = "31554551";
        char ptr[100] = "551";
        int a = KMP(str, strlen(str), ptr, strlen(ptr));
        cout << a << endl;
        a = index_force(str, ptr, 0);
        cout << a << endl;
    }
    return 0;
}