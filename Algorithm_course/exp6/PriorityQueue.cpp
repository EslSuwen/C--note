/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-27 10:18:07
 * @LastEditTime: 2019-05-09 09:14:06
 */
#ifndef _PRIORITY_QUEUE_CPP_
#define _PRIORITY_QUEUE_CPP_
#include <iostream>
using namespace std;
#include "PriorityQueue.h"
void PriorityQueue::siftDown(int start, int m)
{
    // 私有函数：从结点start 开始到m 为止，自上向下比较，
    // 如果子女的值小于父结点的值，则关键码小的上浮，
    // 继续向下层比较，将一个集合局部调整为最小堆。
    int i = start, j = 2 * i + 1; // j 是i 的左子女位置
    pq temp = heap[i];
    while (j <= m)
    {                                                   // 检查是否到最后位置
        if (j < m && heap[j].value > heap[j + 1].value) // 让j 指向两子女中的小者
        {
            pq t = heap[j + 1];
            heap[j + 1] = heap[j];
            heap[j] = t;
        }
        if (temp.value <= heap[j].value) // 小则不做调整
            break;
        else
        { // 否则小者上移, i, j 下降
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    heap[i] = temp; // 回放temp 中暂存的元素
}
void PriorityQueue::siftUp(int start)
{
    // 私有函数：从结点start 开始到结点0 为止，自下向上比较，
    // 如果子女的值小于父结点的值，则相互交换，
    // 这样将集合重新调整为最小堆。关键码比较符<=在E 中定义。
    int j = start, i = (j - 1) / 2;
    pq temp = heap[j];
    while (j > 0)
    { // 沿父结点路径向上直达根
        if (heap[i].value <= temp.value)
            break; // 父结点值小, 不调整
        else
        { // 父结点结点值大, 调整
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;
        }
    }
    heap[j] = temp; // 回送
}
void PriorityQueue::Adjust()
{
    //开始到结点0 为止，自上向下比较，
    //调整为优先队列
    int i = 0, j = 2 * i + 1; // j 是i 的左子女位置
    pq temp = heap[i];
    while (j <= currentSize)
    {                                                             // 检查是否到最后位置
        if (j < currentSize && heap[j].value > heap[j + 1].value) // 让j 指向两子女中的小者
        {
            pq t = heap[j + 1];
            heap[j + 1] = heap[j];
            heap[j] = t;
        }
        if (temp.value <= heap[j].value) // 小则不做调整
            break;
        else
        { // 否则小者上移, i, j 下降
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
        /*   */
    }
    heap[i] = temp; // 回放temp 中暂存的元素
}
PriorityQueue::PriorityQueue(int sz)
{
    // 构造函数：建立大小为sz 的堆
    maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
    heap = new pq[maxHeapSize]; // 创建堆空间
    if (heap == NULL)
    {
        cerr << "堆存储分配失败！" << endl;
        exit(1);
    }
    currentSize = 0; // 建立当前大小
}
PriorityQueue::PriorityQueue(pq arr[], int n)
{
    // 构造函数：用数组arr[ ] 里的元素创建堆
    maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
    heap = new pq[maxHeapSize];
    if (heap == NULL)
    {
        cerr << "堆存储分配失败！" << endl;
        exit(1);
    }
    for (int i = 0; i < n; i++)
        heap[i] = arr[i];
    currentSize = n;                        // 复制堆数组, 建立当前大小
    int currentPos = (currentSize - 2) / 2; // 找最初调整位置：即最后分支结点
    while (currentPos >= 0)
    {                                          // 逐步向上扩大堆
        siftDown(currentPos, currentSize - 1); // 局部自上向下下滑调整
        currentPos--;
    }
}
bool PriorityQueue::Insert(const pq x)
{
    // 将x 插入到最小堆中
    if (currentSize == maxHeapSize)
    { // 堆满
        cout << "Heap Full" << endl;
        return false;
    }
    heap[currentSize] = x; // 插入
    siftUp(currentSize);   // 向上调整
    currentSize++;         // 堆计数加1
    return true;
}
bool PriorityQueue::Remove(pq &x)
{
    // 从堆中删除元素，并用x 返回
    if (currentSize <= 0) // 堆空, 返回false
    {
        cout << "Heap empty" << endl;
        return false;
    }
    x = heap[0];
    heap[0] = heap[--currentSize];
    siftDown(0, currentSize - 1); // 自上向下调整为堆
    return true;                  // 返回最小元素
}
void PriorityQueue::Travesal()
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << heap[i].priority << " " << heap[i].value << endl;
    }
    cout << endl;
}
#endif
