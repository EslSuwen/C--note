/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-20 21:45:47
 * @LastEditTime: 2019-03-21 08:04:08
 */
#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
using namespace std;
const int DefaultSize = 50;    // 栈的默认大小
const int IncreamentSize = 20; // 当栈满时增加的量
template <class T>
class SeqStack
{ // 顺序栈类定义
  private:
    T *elements;            // 栈元素存放数组
    int top;                // 栈顶指针
    int maxSize;            // 栈最大容量
    void overflowProcess(); // 栈的溢出处理
  public:
    SeqStack(int sz = DefaultSize);   // 构造函数
    ~SeqStack();             // 析构函数
    void Push(const T x);    // 进栈
    bool Pop(T &x);          // 出栈
    bool getTop(T &x) const; // 取栈顶内容
    bool IsEmpty() const;
    bool IsFull() const;
    int getSize() const;
    void MakeEmpty();
    void Traverse() const;
};
template <class T>
void SeqStack<T>::overflowProcess()
{
    // 私有函数：当栈满则执行扩充栈存储空间处理
    T *newArray = new T[maxSize + IncreamentSize]; // 创建更大的存储数组
    for (int i = 0; i <= top; i++)
        newArray[i] = elements[i];
    maxSize += IncreamentSize;
    delete[] elements;
    elements = newArray; // 改变elements 指针
};
#include "Stack.cpp"
#endif
