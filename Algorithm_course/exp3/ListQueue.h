/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-21 09:47:38
 * @LastEditTime: 2019-04-03 20:55:11
 */
#ifndef _LIST_QUEUE_H_
#define _LIST_QUEUE_H_
template <class T>
class node
{ //结点类
public:
  T data;
  node *next;
};
template <class T>
class ListQueue
{
private:
  node<T> *head; //头部
  node<T> *end;  //尾部
  int num;       //个数
public:
  ListQueue(); //构造函数
  ~ListQueue();
  bool EnQueue(T temp);  //入队
  bool DeQueue(T &temp); //出队
  void travesal();       //遍历链表
  node<T> *getinter();   //获取链表头用于赋值等
  int getnum();          //获取当前容量
};
#include "ListQueue.cpp"
#endif