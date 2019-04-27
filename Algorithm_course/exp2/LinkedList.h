/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-21 09:47:38
 * @LastEditTime: 2019-03-21 09:57:25
 */
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
template <class T>
class node
{ //结点类
public:
  T data;
  node *next;
};
template <class T>
class test
{
private:
  node<T> *head;   //头部
  node<T> *end;    //尾部
  int num;         //个数
  node<T> *now;    //当前
  node<T> *before; //之前
public:
  test(int a = 0); //构造函数
  ~test();
  void addp1();                        //在头部生成节点   ok
  void addp2();                        //在尾部生成节点    ok
  void addp3(int i);                   //在i处生成节点  ok
  void createp(int i, node<T> *inset); //在i处插入节点,需要一个node对象或指针作为参数  ok
  void deletep(int i);                 //删除节点          ok
  node<T> *getaddp(int i);             //传出地址用于访问和修改节点    ok
  void testall();                      //遍历链表                     ok
  node<T> *getinter();                 //获取链表头用于赋值等        ok
  void showstate();                    //状态查看                  ok
  int getnum();                        //获取当前容量             ok
  void operator=(test<T> &t);          //重载运算符=             ok
  void insetlink(int i, test<T> &t);   //在当前链表的i处插入一个类链表   ok
};
#include "LinkedList.cpp"
#endif