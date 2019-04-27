/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-20 20:25:00
 * @LastEditTime: 2019-03-21 08:02:28
 */
#ifndef _STACK_CPP_
#define _STACK_CPP_
#include <iostream>
using namespace std;
#include "Stack.h"
template <class T>
SeqStack<T>::SeqStack(int size) : top(-1), maxSize(size)
{
    if (maxSize <= 0)
        return;
    elements = new T[maxSize];
    if (elements == NULL)
    {
        cerr << "初始化失败！" << endl;
        exit(1);
    }
}
template <class T>
SeqStack<T>::~SeqStack()
{ // 析构函数
    delete[] elements;
}
template <class T>
void SeqStack<T>::Push(const T x)
{
    if (IsFull() == true)
        overflowProcess(); // 栈满
    elements[++top] = x;   // 栈顶指针先加1, 再进栈
}
template <class T>
bool SeqStack<T>::Pop(T &x)
{ // 函数退出栈顶元素并返回栈顶元素的值
    if (IsEmpty() == true)
        return false;
    x = elements[top--]; // 栈顶指针退1
    return true;         // 退栈成功
}
template <class T>
bool SeqStack<T>::getTop(T &x) const
{ // 若栈不空则函数返回该栈栈顶元素的地址
    if (IsEmpty() == true)
        return false;
    x = elements[top];
    return true;
}
template <class T>
inline bool SeqStack<T>::IsEmpty() const
{
    return top == -1;
}
template <class T>
inline bool SeqStack<T>::IsFull() const
{
    return top == maxSize - 1;
}

template <class T>
inline int SeqStack<T>::getSize() const
{
    return top + 1;
}
template <class T>
inline void SeqStack<T>::MakeEmpty()
{
    top = -1;
}
template <class T>
void SeqStack<T>::Traverse() const
{
    for (int i = 0; i <= top; i++)
        cout << elements[i] << "";
    cout << endl;
}
#endif
