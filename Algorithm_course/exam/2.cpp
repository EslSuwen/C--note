/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @Date: 2019-05-22 16:16:58
 * @LastEditors: Suwen SP\n
 * @LastEditTime: 2019-05-22 16:52:32
 */
#include <iostream>
using namespace std;

struct node
{
    node *next;
    int data;
    node() {}
    node(int n) : data(n) {}
};

void addp(int &num, node &root, int k)
{
    num = num + 1;
    node *p = &root;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    node n(k);
    p->next = &n;
}
void fun(int &num,node &root)
{
    node *p = &root;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    addp(num, root, p->data);
    root = *root.next;
}

int main()
{
    node root();
    int num = 0;
    for (int i = 0; i < 10; i++)
    {
        addp(num, root, i);
    }
    fun(num,root);
    return 0;
}