/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-03 18:39:29
 * @LastEditTime: 2019-04-03 18:59:59
 */

#ifndef _SEQ_QUEUE_CPP_
#define _SEQ_QUEUE_CPP_
#include "SeqQueue.h"
using namespace std;

template <class T>
SeqQueue<T>::SeqQueue(int sz)
{ // 构造函数
    maxSize = sz;
    rear = front = 0;
    assert(elements = new T[maxSize]);
    if (elements == NULL)
    {
        cerr << "初始化队列失败！" << endl;
        exit(1);
    }
}
template <class T>
SeqQueue<T>::~SeqQueue()
{ // 析构函数
    delete[] elements;
}
template <class T>
bool SeqQueue<T>::EnQueue(const T x)
{
    // 若队列不满, 则将x 插入到该队列队尾, 并返回true, 否则返回false
    if (IsFull() == true)
        Increase();              // return false;
    elements[rear] = x;          // 先存入
    rear = (rear + 1) % maxSize; // 尾指针加一
    return true;
}
template <class T>
bool SeqQueue<T>::DeQueue(T &x)
{
    // 若队列不空则函数退队头元素并返回其值
    if (IsEmpty() == true)
        return false;
    x = elements[front];           // 先取队头
    front = (front + 1) % maxSize; // 再队头指针加一
    if (4 * getSize() <= maxSize)
        Decrease();
    return true;
}
template <class T>
bool SeqQueue<T>::getFront(T &x) const
{
    // 若队列不空则函数返回该队列队头元素的值
    if (IsEmpty() == true)
        return false;    // 队列空
    x = elements[front]; // 返回队头元素
    return true;
}
template <class T>
inline void SeqQueue<T>::makeEmpty()
{
    front = rear = 0;
}
template <class T>
inline bool SeqQueue<T>::IsEmpty() const
{
    return front == rear;
}
template <class T>
inline bool SeqQueue<T>::IsFull() const
{
    return (rear + 1) % maxSize == front;
}
template <class T>
inline int SeqQueue<T>::getSize() const
{
    return (rear - front + maxSize) % maxSize;
}
template <class T>
void SeqQueue<T>::output() const
{
    for (int i = front; i != rear; i = (i + 1) % maxSize)
        cout << elements[i] << "";
    cout << "还可容纳" << maxSize - getSize() - 1 << " 个元素" << endl;
}
template <class T>
void SeqQueue<T>::Increase()
{
    T *newArray = new T[2 * maxSize];
    if (newArray == NULL)
    {
        cerr << "初始化队列失败！" << endl;
        exit(1);
    }
    int k = 0;
    for (int i = front; i != rear; i = (i + 1) % maxSize, k++)
        newArray[k] = elements[i];
    delete[] elements;
    elements = newArray;
    front = 0;
    rear = k;
    maxSize *= 2;
}
template <class T>
void SeqQueue<T>::Decrease()
{
    if (maxSize <= DefaultSize)
        return;
    T *newArray = new T[maxSize / 2];
    if (newArray == NULL)
    {
        cerr << "初始化队列失败！" << endl;
        exit(1);
    }
    int k = 0;
    for (int i = front; i != rear; i = (i + 1) % maxSize, k++)
        newArray[k] = elements[i];
    delete[] elements;
    elements = newArray;
    front = 0;
    rear = k;
    maxSize /= 2;
}
#endif