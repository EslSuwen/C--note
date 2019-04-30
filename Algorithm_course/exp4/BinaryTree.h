/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-18 08:01:38
 * @LastEditTime: 2019-04-27 09:44:11
 */
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include <fstream>
#include <iostream>
using namespace std;
template <class T>
struct BinTreeNode
{                                                              // ����������ඨ��
    T data;                                                    // ������
    BinTreeNode<T> *leftChild, *rightChild;                    // ����Ů������Ů����
    BinTreeNode() : leftChild(nullptr), rightChild(nullptr) {} // ���캯��
    BinTreeNode(T x, BinTreeNode<T> *l = nullptr, BinTreeNode<T> *r = nullptr) : data(x), leftChild(l), rightChild(r) {}
};
template <class T>
class BinaryTree
{ // �������ඨ��
  public:
    BinTreeNode<T> *root;                                      // �������ĸ�ָ��
    T RefValue;                                                // ��������ֹͣ��־
    void CreateBinTree(istream &in, BinTreeNode<T> *&subTree); // �����������뽨��
    void CreateBinTreeString(const string &desStr);            // ���ַ������뽨��
    void destroy(BinTreeNode<T> *subTree);
    int Height(BinTreeNode<T> *subTree) const;                                 // �������߶�
    int Size(BinTreeNode<T> *subTree) const;                                   // ���ؽ����
    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *t);        // ���ظ����
    void PreOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t));  // ǰ�����
    void InOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t));   // �������
    void PostOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t)); // �������
    void PrintBTree(BinTreeNode<T> *BT);                                       //��������������
    void PreOrderStack(void (*)(BinTreeNode<T> *p));                           //�ǵݹ�ǰ�����

    friend istream &operator>>(istream *in, BinaryTree<T> &Tree);  //���ز���������
    friend ostream &operator<<(ostream *out, BinaryTree<T> &Tree); //���ز��������

    BinaryTree() : root(nullptr) {}                         // ���캯��
    BinaryTree(T value) : root(nullptr), RefValue(value) {} // ���캯��
    // BinaryTree (BinaryTree<T>& s); // ���ƹ��캯��
    void CreatePreOrder(ifstream &in) { CreateBinTree(in, root); }
    ~BinaryTree() { destroy(root); }           // ��������
    bool IsEmpty() { return root == nullptr; } // �ж������շ�
    int Height() { return Height(root); }      // �����߶�
    int Size() { return Size(root); }          // ������
    BinTreeNode<T> *Parent(BinTreeNode<T> *t)
    { // ����˫�׽��
        return (root == nullptr || root == t) ? nullptr : Parent(root, t);
    }
    BinTreeNode<T> *LeftChild(BinTreeNode<T> *t)
    { // ��������Ů
        return (t != nullptr) ? t->leftChild : nullptr;
    }
    BinTreeNode<T> *RightChild(BinTreeNode<T> *t)
    { // ��������Ů
        return (t != nullptr) ? t->rightChild : nullptr;
    }
    BinTreeNode<T> *getRoot() const { return root; }                             // ȡ��
    void Traverse(BinTreeNode<T> *subTree, ostream &out);                        //ǰ��������
    void PreOrder(void (*visit)(BinTreeNode<T> *t)) { PreOrder(root, visit); }   // ǰ�����
    void InOrder(void (*visit)(BinTreeNode<T> *t)) { InOrder(root, visit); }     // �������
    void PostOrder(void (*visit)(BinTreeNode<T> *t)) { PostOrder(root, visit); } // �������
    static void visit(BinTreeNode<T> *t) { cout << t->data << " "; };
};
template <class T>
istream &operator>>(istream &in, BinaryTree<T> &Tree)
{
    Tree.CreateBinTree(in, Tree.root);
    return in;
}
template <class T>
ostream &operator<<(ostream &out, BinaryTree<T> &Tree)
{
    out << "binary tree pre-traverse:" << endl;
    Tree.Traverse(Tree.root, out);
    out << endl;
    return out;
}
#include "BinaryTree.cpp"
#endif
