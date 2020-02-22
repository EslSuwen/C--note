/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-20 21:41:22
 * @LastEditTime: 2019-03-21 09:56:27
 */

#include "DoubleStack.h"
#include "LinkedList.h"
#include "LinkedStack.h"
int main()
{
    //链表测试
    {
        test<int> my(5);
        {
            node<int> *n = my.getinter();
            for (int i = 1; i <= 5; i++)
            {
                n->data = i;
                n = n->next;
            }
            my.testall();
        }

        cout << "create link succeed!" << endl;

        {
            my.addp1(); //头部增一测试
            my.testall();
        }
        cout << "head add test succeed!" << endl;

        {
            my.addp2(); //尾部增一测试
            my.testall();
        }
        cout << "end add test succeed!" << endl;

        {
            my.addp3(3); //任意位置增一测试
            my.testall();
        }
        cout << "random add test succeed!" << endl;

        { //删除节点测试
            my.deletep(1);
            my.deletep(3);
            my.deletep(6);
            my.testall();
            cout << "delete test succeed!" << endl;
        }

        cout << "following is another subject 'A' copyed from 'my'" << endl;
        test<int> A(5);
        A = my;
        {
            A.testall();
            cout << "operator ''=''  function test succeed!" << endl;
        }

        cout << "expand my with the function insetlink()" << endl; //链表间的插入测试
        my.insetlink(3, A);
        {
            my.testall();
            cout << "succeed!" << endl;
        }

        cout << endl;
        my.insetlink(10, A); //尾部测试
        {
            my.testall();
        }
    }
    //链栈测试
    {
        LinkedStack<int> test;
        int i;
        cout << test.getTop(i) << endl;
        test.Push(1);
        cout << test.getTop(i) << endl;
        test.Push(2);
        cout << test.getTop(i) << endl;
        test.Pop(i);
        cout << i << endl;
        test.Pop(i);
        cout << i << endl;
    }
    //双栈测试
    {
        DoubleStack<int> my(10);
        for (int i = 0; i < 5; i++)
            my.Push1(i);
        my.Push2(6);
        my.Traverse();
        int temp;
        my.Pop1(temp);
        cout << temp << endl;
        my.Pop1(temp);
        cout << temp << endl;
        my.Traverse();
        my.getTop(temp, 0);
        my.getTop(temp, 1);
        cout << temp << endl;
        my.MakeEmpty();
        my.Traverse();
    }
    return 0;
}
