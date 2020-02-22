/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-21 08:16:00
 * @LastEditTime: 2019-03-21 09:24:38
 */
#ifndef _DOUBLESTACK_H_
#define _DOUBLESTACK_H_
#include <iostream>
using namespace std;
const int DefaultSize = 50;    // 栈的默认大小
template <class T>
class DoubleStack
{ // 顺序栈类定义
  private:
    T *elements;            // 栈元素存放数组
    int top[2];                // 栈顶指针
    int bot[2];                 //栈底指针
    int maxSize;            // 栈最大容量
  public:
    DoubleStack(int sz = DefaultSize);   // 构造函数
    ~DoubleStack();             // 析构函数
    bool Push1(const T x);    // 进栈
    bool Push2(const T x);
    bool Pop1(T &x);          // 出栈
    bool Pop2(T &x);
    bool getTop(T &x,int p) const; // 取栈顶内容
    bool IsEmpty1() const;
    bool IsEmpty2() const;
    bool IsFull() const;
    int getSize() const;
    void MakeEmpty();
    void Traverse() const;
};
#include "DoubleStack.cpp"
#endif
