/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen HS\n
 * @LastEditors: Suwen HS\n
 * @Date: 2019-03-20 21:37:19
 * @LastEditTime: 2019-03-20 22:27:31
 */
#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include <cassert>
#include <iostream>
using namespace std;
template <class T>
struct LinkNode
{
  T data;
  LinkNode<T> *link;
  LinkNode(LinkNode<T> *ptr = NULL) { link = ptr; }
  LinkNode(const T &item, LinkNode<T> *ptr = NULL) : data(item), link(ptr) {}
};
template <class T>
class LinkedStack
{
private:
  LinkNode<T> *top;

public:
  LinkedStack();
  ~LinkedStack();
  void Push(const T x);
  bool Pop(T &x);
  bool getTop(T &x) const;
  bool IsEmpty() const;
  int getSize() const;
  void makeEmpty();
};
#include "LinkedStack.cpp"
#endif