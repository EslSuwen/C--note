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
{                                                              // 二叉树结点类定义
    T data;                                                    // 数据域
    BinTreeNode<T> *leftChild, *rightChild;                    // 左子女、右子女链域
    BinTreeNode() : leftChild(nullptr), rightChild(nullptr) {} // 构造函数
    BinTreeNode(T x, BinTreeNode<T> *l = nullptr, BinTreeNode<T> *r = nullptr) : data(x), leftChild(l), rightChild(r) {}
};
template <class T>
class BinaryTree
{ // 二叉树类定义
  public:
    BinTreeNode<T> *root;                                      // 二叉树的根指针
    T RefValue;                                                // 数据输入停止标志
    void CreateBinTree(istream &in, BinTreeNode<T> *&subTree); // 从输入流读入建树
    void CreateBinTreeString(const string &desStr);            // 从字符串读入建树
    void destroy(BinTreeNode<T> *subTree);
    int Height(BinTreeNode<T> *subTree) const;                                 // 返回树高度
    int Size(BinTreeNode<T> *subTree) const;                                   // 返回结点数
    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *t);        // 返回父结点
    void PreOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t));  // 前序遍历
    void InOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t));   // 中序遍历
    void PostOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *t)); // 后序遍历
    void PrintBTree(BinTreeNode<T> *BT);                                       //广义表输出二叉树
    void PreOrderStack(void (*)(BinTreeNode<T> *p));                           //非递归前序遍历

    friend istream &operator>>(istream *in, BinaryTree<T> &Tree);  //重载操作：输入
    friend ostream &operator<<(ostream *out, BinaryTree<T> &Tree); //重载操作：输出

    BinaryTree() : root(nullptr) {}                         // 构造函数
    BinaryTree(T value) : root(nullptr), RefValue(value) {} // 构造函数
    // BinaryTree (BinaryTree<T>& s); // 复制构造函数
    void CreatePreOrder(ifstream &in) { CreateBinTree(in, root); }
    ~BinaryTree() { destroy(root); }           // 析构函数
    bool IsEmpty() { return root == nullptr; } // 判二叉树空否
    int Height() { return Height(root); }      // 求树高度
    int Size() { return Size(root); }          // 求结点数
    BinTreeNode<T> *Parent(BinTreeNode<T> *t)
    { // 返回双亲结点
        return (root == nullptr || root == t) ? nullptr : Parent(root, t);
    }
    BinTreeNode<T> *LeftChild(BinTreeNode<T> *t)
    { // 返回左子女
        return (t != nullptr) ? t->leftChild : nullptr;
    }
    BinTreeNode<T> *RightChild(BinTreeNode<T> *t)
    { // 返回右子女
        return (t != nullptr) ? t->rightChild : nullptr;
    }
    BinTreeNode<T> *getRoot() const { return root; }                             // 取根
    void Traverse(BinTreeNode<T> *subTree, ostream &out);                        //前序遍历输出
    void PreOrder(void (*visit)(BinTreeNode<T> *t)) { PreOrder(root, visit); }   // 前序遍历
    void InOrder(void (*visit)(BinTreeNode<T> *t)) { InOrder(root, visit); }     // 中序遍历
    void PostOrder(void (*visit)(BinTreeNode<T> *t)) { PostOrder(root, visit); } // 后序遍历
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
