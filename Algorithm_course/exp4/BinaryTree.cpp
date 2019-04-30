/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-18 08:01:46
 * @LastEditTime: 2019-04-27 09:49:38
 */
#ifndef _BINARY_TREE_CPP
#define _BINARY_TREE_CPP
#include "BinaryTree.h"
#include <cassert>
#include <iostream>
#include <stack>
template <class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *t)
{
    // ˽�к���: �ӽ��subTree ��ʼ, �������t ��˫��, ���ҵ��򷵻�˫�׽���ַ, ���򷵻�nullptr
    if (subTree == nullptr)
        return nullptr;
    if (subTree->leftChild == t || subTree->rightChild == t)
        return subTree; // �ҵ�, ���ظ�����ַ
    BinTreeNode<T> *p;
    if ((p = Parent(subTree->leftChild, t)) != nullptr) // �ݹ���������������
        return p;
    else
        return Parent(subTree->rightChild, t); // �ݹ�������������
}
template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *subTree)
{
    // ˽�к���: ɾ����ΪsubTree ������
    if (subTree != nullptr)
    {
        destroy(subTree->leftChild);  // ɾ��������
        destroy(subTree->rightChild); // ɾ��������
        delete subTree;               // ɾ�������
    }
}
template <class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree, ostream &out)
{
    if (subTree != nullptr)
    {
        out << subTree->data << " ";
        Traverse(subTree->leftChild, out);
        Traverse(subTree->rightChild, out);
    }
}
template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t))
{
    // ˽�к���: ���������visit��������subTree
    if (subTree != nullptr)
    {
        InOrder(subTree->leftChild, visit);  // ����������
        visit(subTree);                      // ���ʸ����
        InOrder(subTree->rightChild, visit); // ����������
    }
}
template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t))
{
    // ˽�к���: ǰ�������visit��������subTree
    if (subTree != nullptr)
    {
        visit(subTree);                       // ���ʸ����
        PreOrder(subTree->leftChild, visit);  // ����������
        PreOrder(subTree->rightChild, visit); // ����������
    }
}
template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t))
{
    // ˽�к���: ���������visit��������subTree
    if (subTree != nullptr)
    {
        PostOrder(subTree->leftChild, visit);  // ����������
        PostOrder(subTree->rightChild, visit); // ����������
        visit(subTree);                        // ���ʸ����
    }
}
template <class T>
void BinaryTree<T>::PreOrderStack(void (*visit)(BinTreeNode<T> *p))
{
    stack<BinTreeNode<T> *> S;
    BinTreeNode<T> *p = root;
    S.push(nullptr);
    while (p != nullptr)
    {
        visit(p);
        if (p->rightChild != nullptr)
            S.push(p->rightChild);
        if (p->leftChild != nullptr)
            p = p->leftChild;
        else
        {
            p = S.top();
            S.pop();
        }
    }
}
template <class T>
void BinaryTree<T>::PrintBTree(BinTreeNode<T> *BT)
{
    if (BT != nullptr)
    {
        cout << BT->data;
        if (BT->leftChild != nullptr || BT->rightChild != nullptr)
        {
            cout << "(";
            PrintBTree(BT->leftChild);
            cout << ",";
            PrintBTree(BT->rightChild);
            cout << ")";
        }
    }
}
template <class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree) const
{
    // ˽�к��������ö�������������㷨����������Ľ�����
    if (subTree == nullptr)
        return 0; // ����
    else
        return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}
template <class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree) const
{
    // ˽�к��������ö�������������㷨����������ĸ߶Ȼ����
    if (subTree == nullptr)
        return 0; // �����߶�Ϊ0
    else
    {
        int i = Height(subTree->leftChild);
        int j = Height(subTree->rightChild);
        return (i < j) ? j + 1 : i + 1;
    }
}
template <class T>
void BinaryTree<T>::CreateBinTreeString(const string &desStr)
{
    //���ݹ�����ַ�����ʼ���������
    if (desStr == "")
        return;
    BinTreeNode<T> *lastNode = nullptr;
    stack<BinTreeNode<T> *> nodeStack;
    bool isLeft = true;
    int curIt = 0;
    char ch = desStr.at(curIt);
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            nodeStack.push(lastNode);
            isLeft = true;
            break;
        case ')':
            isLeft = false;
            if (nodeStack.empty() != true)
                nodeStack.pop();
            break;
        case ',':
            isLeft = false;
            break;
        default:
            lastNode = new BinTreeNode(ch);
            if (root == nullptr)
            {
                root = lastNode;
            }
            else
            {
                BinTreeNode<T> *parentNode = nodeStack.top();
                if (isLeft == true)
                {
                    parentNode->leftChild = lastNode;
                }
                else
                {
                    parentNode->rightChild = lastNode;
                }
            }
        }
        ++curIt;
        if (curIt == desStr.length())
        {
            break;
        }
        ch = desStr.at(curIt);
    } //while end
}
template <class T>
void BinaryTree<T>::CreateBinTree(istream &in, BinTreeNode<T> *&subTree)
{
    stack<BinTreeNode<T> *> s;
    subTree = nullptr;
    BinTreeNode<char> *p, *t;
    int k;
    T ch;
    in >> ch;
    while (ch != RefValue)
    {
        switch (ch)
        {
        case '(':
            s.push(p);
            k = 1;
            break;
        case ')':
            t = s.top();
            s.pop();
            break;

        case ',':
            k = 2;
            break;
        default:
            p = new BinTreeNode(ch);
            if (subTree == nullptr)
                subTree = p;
            else if (k == 1)
            {
                t = s.top();
                t->leftChild = p;
            }
            else
            {
                t = s.top();
                t->rightChild = p;
            }
        }
        in >> ch;
    }
};
#endif
