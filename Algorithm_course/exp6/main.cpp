/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-05-08 21:51:45
 * @LastEditTime: 2019-05-09 09:23:10
 */
#include "PriorityQueue.h"

int main()
{
    //优先队列测试
    int priority, value, i = 5;
    pq *arr = new pq[20]();
    //控制台输入
    /* while (1)
    {
        cin >> priority >> value;
        if (priority == -1 && value == -1)
            break;
        pq test(priority, value);
        arr[i++] = test;
    } */
    cout << "测试数据：1 5 2 3 3  5 4 20 5 10 -1 -1" << endl;
    arr[0] = pq(1, 15);
    arr[1] = pq(2, 3);
    arr[2] = pq(3, 5);
    arr[3] = pq(4, 20);
    arr[4] = pq(5, 10);
    for (int k = 0; k < i; k++)
    {
        cout << arr[k].priority << " " << arr[k].value << endl;
    }
    cout << endl;
    PriorityQueue heap(arr, i);
    heap.Adjust();
    heap.Travesal();
    return 0;
}