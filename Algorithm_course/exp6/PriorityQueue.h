/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-05-08 21:48:46
 * @LastEditTime: 2019-05-09 09:15:37
 */
#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
#include <iostream>
const int DefaultSize = 10;
using namespace std;
struct pq
{
    int priority; //默认顺序
    int value;    //优先权重
    pq(int p = 0, int v = 0) : priority(p), value(v) {}
};
class PriorityQueue
{

private:
    pq *heap;        // 最小堆元素存储数组
    int currentSize; // 最小堆当前元素个数
    int maxHeapSize; // 最小堆最大容量

public:
    void siftDown(int start, int m);     // 调整算法：从start 开始向下调整到m
    void siftUp(int start);              // 调整算法：从start 开始向上调整
    PriorityQueue(int sz = DefaultSize); // 构造函数：长度为sz
    PriorityQueue(pq arr[], int n);      // 构造函数：用数组arr[ ] 里的元素创建堆
    ~PriorityQueue() { delete[] heap; }  // 析构函数
    bool Insert(const pq d);             // 插入
    bool Remove(pq &d);                  // 删除
    bool IsEmpty() const;                // 判堆空否
    bool IsFull() const;                 // 判堆满否
    void MakeEmpty();                    // 置空堆
    void Adjust();                       //调整为优先队列
    void Travesal();                     //遍历
};
inline bool PriorityQueue::IsEmpty() const
{
    // 判堆空否
    return currentSize == 0;
}
inline bool PriorityQueue::IsFull() const
{
    // 判堆满否
    return currentSize == maxHeapSize;
}
inline void PriorityQueue::MakeEmpty()
{
    // 置空堆
    currentSize = 0;
}
#include "PriorityQueue.cpp"

#endif