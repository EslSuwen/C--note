/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-27 10:17:55
 * @LastEditTime: 2019-04-30 09:13:31
 */

#ifndef _HEAP_H_
#define _HEAP_H_
#include <iostream>
using namespace std;
const int DefaultSize = 10;
template <class T>
class MinHeap
{ // 最小堆类定义
  private:
    T *heap;         // 最小堆元素存储数组
    int currentSize; // 最小堆当前元素个数
    int maxHeapSize; // 最小堆最大容量

  public:
    void siftDown(int start, int m); // 调整算法：从start 开始向下调整到m
    void siftUp(int start);          // 调整算法：从start 开始向上调整
    MinHeap(int sz = DefaultSize);   // 构造函数：长度为sz
    MinHeap(T arr[], int n);         // 构造函数：用数组arr[ ] 里的元素创建堆
    ~MinHeap() { delete[] heap; }    // 析构函数
    bool Insert(const T d);          // 插入
    bool Remove(T &d);               // 删除
    bool IsEmpty() const;            // 判堆空否
    bool IsFull() const;             // 判堆满否
    void MakeEmpty();                // 置空堆
    void Travesal();                 //遍历
};
template <class T>
inline bool MinHeap<T>::IsEmpty() const
{
    // 判堆空否
    return currentSize == 0;
}
template <class T>
inline bool MinHeap<T>::IsFull() const
{
    // 判堆满否
    return currentSize == maxHeapSize;
}
template <class T>
inline void MinHeap<T>::MakeEmpty()
{
    // 置空堆
    currentSize = 0;
}
#include "Heap.cpp"
#endif
