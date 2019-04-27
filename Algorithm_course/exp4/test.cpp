/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-18 11:38:35
 * @LastEditTime: 2019-04-18 16:23:24
 */

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
struct BTreeNode
{
    T data;

    BTreeNode<T> *leftNode;
    BTreeNode<T> *rightNode;
};

typedef BTreeNode<int> BTINT;

template <class T>
class BTree
{
    BTreeNode<T> *m_root = nullptr;
    BTreeNode<T> *getNewNode(T val)
    {
        BTreeNode<T> *newNode = new (std::nothrow) BTreeNode<T>();
        newNode->data = val;
        if (newNode == nullptr)
        {
            cerr << "申请新的内存失败！" << endl;
            this->destroyTree(m_root);
            exit(1);
        }
        return newNode;
    }

  public:
    BTree() : m_root(nullptr) {}
    ~BTree() {}
    BTreeNode<T> *const getRootNode()
    {
        return m_root;
    }
    void initBinaryTree(const string &desStr)
    {
        //根据广义表字符串初始构造二叉树
        if (desStr == "")
            return;
        BTreeNode<T> *lastNode = nullptr;
        stack<BTreeNode<T> *> nodeStack;
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
                lastNode = this->getNewNode(ch);
                if (m_root == nullptr)
                {
                    m_root = lastNode;
                }
                else
                {
                    BTreeNode<T> *parentNode = nodeStack.top();
                    if (isLeft == true)
                    {
                        parentNode->leftNode = lastNode;
                    }
                    else
                    {
                        parentNode->rightNode = lastNode;
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

    void levelOrder(BTreeNode<T> *pCurNode) const
    {
        if (pCurNode == nullptr)
            return;
        BTreeNode<T> *curNode = pCurNode;
        queue<BTreeNode<T> *> que;
        que.push(curNode);
        while (que.empty() == false)
        {
            curNode = que.front();
            que.pop();
            cout << curNode->data << endl;
            if (curNode->leftNode != nullptr)
                que.push(curNode->leftNode);
            if (curNode->rightNode != nullptr)
                que.push(curNode->rightNode);
        }
    }

    void preOrderPrint(BTreeNode<T> *pCurNode) const
    {
        //前序遍历
        if (pCurNode == nullptr)
            return;
        cout << pCurNode->data << endl;
        this->preOrderPrint(pCurNode->leftNode);
        this->preOrderPrint(pCurNode->rightNode);
    }

    void inOrderPrint(BTreeNode<T> *pCurNode) const
    {
        //中序遍历
        if (pCurNode == nullptr)
            return;
        this->inOrderPrint(pCurNode->leftNode);
        cout << pCurNode->data << endl;
        this->inOrderPrint(pCurNode->rightNode);
    }
    void postOrderPrint(BTreeNode<T> *pCurNode) const
    {
        //后序遍历
        if (pCurNode == nullptr)
            return;
        this->postOrderPrint(pCurNode->leftNode);
        this->postOrderPrint(pCurNode->rightNode);
        cout << pCurNode->data << endl;
    }
    void PreOrderStack(BTreeNode<T> *pCurNode) const
    {
        stack<BTreeNode<T> *> S;
        BTreeNode<T> *p = pCurNode;
        S.push(NULL);
        while (p != NULL)
        {
            cout << p->data << endl;
            if (p->rightNode != NULL)
                S.push(p->rightNode);
            if (p->leftNode != NULL)
                p = p->leftNode;
            else
            {
                p = S.top();
                S.pop();
            }
        }
    }

    void destroyTree(BTreeNode<T> *pCurNode)
    {
        //后序遍历方式，销毁整颗树
        if (pCurNode == nullptr)
            return;
        this->destroyTree(pCurNode->leftNode);
        this->destroyTree(pCurNode->rightNode);
        delete pCurNode;
        pCurNode = nullptr;
    }
};

int main()
{

    BTree<char> *binaryTree = new BTree<char>();
    binaryTree->initBinaryTree("1(2(3,4),5(6,7))");
    cout << "1(2(3,4),5(6,7))" << endl;
    cout << "前序遍历" << endl;
    binaryTree->preOrderPrint(binaryTree->getRootNode());
    cout << "非递归遍历" << endl;
    binaryTree->PreOrderStack(binaryTree->getRootNode());
    cout << endl;
    binaryTree->destroyTree(binaryTree->getRootNode());
    cout << endl;
    return 0;
}