/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-20 21:37:41
 * @LastEditTime: 2019-03-20 22:28:37
 */
#ifndef _LINKED_STACK_CPP_
#define _LINKED_STACK_CPP_

#include "LinkedStack.h"

using namespace std;
template <class T>
LinkedStack<T>::LinkedStack() : top(NULL) {}
template <class T>
LinkedStack<T>::~LinkedStack()
{
    makeEmpty();
}
template <class T>
void LinkedStack<T>::makeEmpty()
{
    while (top != NULL)
    {
        LinkNode<T> *p = top;
        top = top->link;
        delete p;
    }
}
template <class T>
void LinkedStack<T>::Push(const T x)
{
    top = new LinkNode<T>(x, top); // 创建新的含x 的结点
    assert(top != NULL);
}
template <class T>
bool LinkedStack<T>::Pop(T &x)
{
    if (IsEmpty())
        return false;
    LinkNode<T> *p = top;
    top = top->link;
    x = p->data;
    delete p;
    return true;
}
template <class T>
bool LinkedStack<T>::getTop(T &x) const
{
    if (IsEmpty() == true)
        return false;
    x = top->data;
    return true;
}
template <class T>
inline bool LinkedStack<T>::IsEmpty() const
{
    return (top == NULL) ? true : false;
}
template <class T>
int LinkedStack<T>::getSize() const
{
    LinkNode<T> *p = top;
    int k = 0;
    while (p != NULL)
    {
        p = p->link;
        k++;
    }
    return k;
}
#endif