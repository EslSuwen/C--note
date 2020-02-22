/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-03 18:39:37
 * @LastEditTime: 2019-04-03 22:03:35
 */
#ifndef _SEQ_QUEUE_H_
#define _SEQ_QUEUE_H_
#include <cassert>
#include <iostream>
using namespace std;
const int DefaultSize = 5;
template <class T>
class SeqQueue
{ // 循环队列类定义
private:
  int rear, front; // 队尾与队头指针
  T *elements;     // 队列存放数组
  int maxSize;     // 队列最大容量
  void Increase(); // 当队列满是增大一倍
  void Decrease(); // 当队列中元素个数低于空间的1/4 时缩减一半
public:
  SeqQueue(int sz = DefaultSize); // 构造函数
  ~SeqQueue();                    // 析构函数
  bool EnQueue(const T x);        // 新元素进队列
  bool DeQueue(T &x);             // 退出队头元素
  bool getFront(T &x) const;      // 取队头元素值
  void makeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int getSize() const;
  void output() const;
};
#include "SeqQueue.cpp"
#endif
