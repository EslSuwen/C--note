/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-20 18:55:23
 * @LastEditTime: 2019-04-03 20:53:52
 */

#ifndef _LIST_QUEUE_
#define _LIST_QUEUE_
#include "ListQueue.h"
#include <iostream>
using namespace std;

template <class T>
ListQueue<T>::ListQueue()
{
    num = 0;
    head = new node<T>;
    end = head;
}
template <class T>
int ListQueue<T>::getnum()
{
    return num;
}

template <class T>
ListQueue<T>::~ListQueue()
{
    delete[] head;
}

template <class T>
bool ListQueue<T>::EnQueue(T temp)
{
    if (num == 0)
    {
        head->data = temp;
        num++;
        return true;
    }
    node<T> *s = new node<T>;
    s->data = temp;
    end->next = s;
    end = s;
    num++;
    return true;
}
template <class T>
bool ListQueue<T>::DeQueue(T &temp)
{
    if (num == 0)
        return false;
    node<T> *dequeue = head;
    temp = head->data;
    head = head->next;
    delete[] dequeue;
    num--;
    return true;
}
template <class T>
node<T> *ListQueue<T>::getinter()
{
    return head;
}

template <class T>
void ListQueue<T>::travesal()
{
    node<T> *current = head;
    if (num == 0)
        return;
    while (current != end)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;
}
#endif