/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-20 18:55:23
 * @LastEditTime: 2019-03-21 09:51:17
 */
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
void test<T>::operator=(test<T> &t)
{
    if (this->getnum() != t.getnum())
    {
        cout << "error!" << endl;
    }
    else
    {
        int j = t.getnum();
        for (int n = 1; n <= j; n++)
        {
            (this->getaddp(n))->data = (t.getaddp(n))->data;
        }
    }
}

template <class T>
test<T>::test(int a)
{
    num = a;
    head = new node<T>;
    end = head;
    for (int i = 1; i <= a; i++)
    {
        node<T> *s = new node<T>;
        end->next = s;
        end = s;
    }
}
template <class T>
int test<T>::getnum()
{
    return num;
}

template <class T>
test<T>::~test()
{
    delete[] head;
}

template <class T>
void test<T>::addp1()
{
    num = num + 1;
    node<T> *s = new node<T>;
    s->next = head;
    head = s;
}

template <class T>
void test<T>::addp2()
{
    num = num + 1;
    node<T> *s = new node<T>;
    end->next = s;
    end = s;
}
template <class T>
void test<T>::addp3(int i)
{
    if (i >= 1 && i <= num)
    {
        node<T> *t = head;
        for (int j = 1; j <= i - 1; j++)
        {
            t = t->next;
        }
        node<T> *behind = t->next;
        node<T> *add = new node<T>;
        t->next = add;
        add->next = behind;
        num = num + 1;
    }
    else
    {
        cout << "error:  out of rage" << endl;
    }
}
template <class T>
node<T> *test<T>::getinter()
{
    return head;
}
template <class T>
void test<T>::showstate()
{
    cout << "recent data:" << endl;
    cout << "the length       :" << num << endl;
    cout << "the begin address:" << (int)head << endl;
    cout << "the end address  :" << (int)end << endl;
}
template <class T>
void test<T>::createp(int i, node<T> *inset)
{
    if (i >= 1 && i <= num)
    {
        node<T> *t = head;
        for (int j = 1; j <= i - 1; j++)
        {
            t = t->next;
        }
        node<T> *behind = t->next;
        node<T> *add = inset;
        t->next = add;
        add->next = behind;
        num = num + 1;
    }
    else
    {
        cout << "error:  out of rage" << endl;
    }
}

template <class T>
void test<T>::deletep(int i)
{
    if (i >= 1 && i <= num)
    {
        if (i == 1)
        {
            node<T> *deletedone = head;
            head = head->next;
            delete[] deletedone;
        }
        else
        {
            node<T> *p = head;
            for (int j = 1; j <= i - 2; j++)
            {
                p = p->next;
            }
            node<T> *deletedone = p->next;
            p->next = (p->next)->next;
            delete[] deletedone;
        }
        num--;
    }
    else
    {

        cout << "node do not exist" << endl;
    }
}

template <class T>
node<T> *test<T>::getaddp(int i)
{
    if (i >= 1 && i <= num)
    {
        node<T> *t = head;
        for (int j = 1; j <= i - 1; j++)
        {
            t = t->next;
        }
        return t;
    }
    else
    {
        cout << "error:node do not exist" << endl;
        return head;
    }
}

/*-----------------辅助函数-------------*/
template <class T>
void copylinklist(test<T> &x, test<T> &y)
{ //复制  把后者的数据复制给前者（若不同长度则尾部数据有遗失）
    int i = x.getnum();
    int j = y.getnum();
    for (int m = 1, n = 1; m <= i && n <= j; m++, n++)
    {
        (x.getaddp(m))->data = (y.getaddp(n))->data;
    }
}

template <class T>
void test<T>::insetlink(int i, test<T> &t)
{
    this->num = this->num + t.num; //扩充链表大小
    int begin = i;
    int end = t.getnum();
    for (int j = 1; j <= end; j++)
    {
        node<T> *u = new node<T>;
        u->data = t.getaddp(j)->data;
        this->createp(begin, u);
        begin = begin + 1;
    }
}

template <class T>
void test<T>::testall()
{
    node<T> *current = head;
    while (current != end)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}