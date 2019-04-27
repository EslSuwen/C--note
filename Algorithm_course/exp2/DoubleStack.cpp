/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-20 22:52:17
 * @LastEditTime: 2019-03-21 09:36:56
 */
#ifndef _DOUBLESTACK_CPP_
#define _DOUBLESTACK_CPP_
#include "DoubleStack.h"
template <class T>
DoubleStack<T>::DoubleStack(int size)
{
    maxSize = size;
    top[0] = bot[0] = -1;
    top[1] = bot[1] = size;
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
DoubleStack<T>::~DoubleStack()
{ // 析构函数
    delete[] elements;
}

template <class T>
bool DoubleStack<T>::Push1(const T x)
{
    if (IsFull() == true)
        return false;
    elements[++top[0]] = x; // 栈顶指针先加1, 再进栈
    return true;
}

template <class T>
bool DoubleStack<T>::Push2(const T x)
{
    if (IsFull() == true)
        return false;
    elements[--top[1]] = x; // 栈顶指针先减1, 再进栈
    return true;
}
template <class T>
bool DoubleStack<T>::Pop1(T &x)
{ // 函数退出栈顶元素并返回栈顶元素的值
    if (IsEmpty1() == true)
        return false;
    x = elements[top[0]--]; // 栈顶指针退1
    return true;            // 退栈成功
}
template <class T>
bool DoubleStack<T>::Pop2(T &x)
{ // 函数退出栈顶元素并返回栈顶元素的值
    if (IsEmpty2() == true)
        return false;
    x = elements[top[1]++]; // 栈顶指针退1
    return true;            // 退栈成功
}
template <class T>
bool DoubleStack<T>::getTop(T &x, int p) const
{ // 若栈不空则函数返回该栈栈顶元素的地址
    if (p == 0 && !IsEmpty1())
    {
        x = elements[top[p]];
        return true;
    }
    else if (p == 1 && !IsEmpty2())
    {
        x = elements[top[p]];
        return true;
    }
    else
        return false;
}
template <class T>
inline bool DoubleStack<T>::IsEmpty1() const
{
    return top[0] == bot[0];
}
template <class T>
inline bool DoubleStack<T>::IsEmpty2() const
{
    return top[1] == bot[1];
}
template <class T>
inline bool DoubleStack<T>::IsFull() const
{
    return top[1] - top[0] == 1;
}

template <class T>
inline int DoubleStack<T>::getSize() const
{
    return top[0] + size - top[1] + 1;
}
template <class T>
inline void DoubleStack<T>::MakeEmpty()
{
    top[0] = -1;
    top[1] = maxSize;
}
template <class T>
void DoubleStack<T>::Traverse() const
{
    cout << "Stack 1:";
    for (int i = 0; i <= top[0]; i++)
        cout << "[" << i << "]"
             << ":" << elements[i] << " ";
    cout << "\nStack 2:";
    for (int i = bot[1] - 1; i >= top[1]; i--)
        cout << "[" << i << "]"
             << ":" << elements[i] << " ";
    cout << endl;
}
#endif