/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-27 10:18:22
 * @LastEditTime: 2019-04-30 09:21:51
 */
#include "BinThrTree.h"
#include "Heap.h"
int main()
{
    { //�Ѳ���
        cout << "�Ѳ�����\n";
        int *a = new int[5]{5, 4, 2, 3, 1};
        MinHeap<int> heap(a, 5);
        heap.Travesal();
    }

    { //��������������
        cout << "����������������\n";
        int a1[10] = {1, 2, 3, '#', '#', 4, '#', '#', 5, 6};
        int a2[15] = {1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8};
        BinaryTreeThd<int> btt1(a1, 10, 0, '#');
        BinaryTreeThd<int> btt2(a2, 15, 0, '#');
        cout << "����������������������\n";
        btt1.InorderThreading();
        btt1._InorderThd();
        cout << endl;
        btt2.InorderThreading();
        btt2._InorderThd();
        cout << endl;
    }
    return 0;
}