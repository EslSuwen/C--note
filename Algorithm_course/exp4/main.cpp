/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-18 08:01:53
 * @LastEditTime: 2019-04-18 16:45:45
 */
#include "BinaryTree.h"
int main()
{
    BinaryTree<char> tree('#'), tree1('#');

    cout << "const string : 1(2(3,4),5(6,7))" << endl;
    tree.CreateBinTreeString("1(2(3,4),5(6,7))");
    cout << "前序递归输出：" << endl;
    tree.PreOrder(tree.visit);
    cout << "\n非递归输出：" << endl;
    tree.PreOrderStack(tree.visit);
    cout << "请输入一个二叉树以'#'结束，例如：1(2,3)：" << endl;
    cin >> tree1;
    cout << "前序递归输出：" << endl;
    tree1.PreOrder(tree.visit);
    cout << "\n非递归输出：" << endl;
    tree1.PreOrderStack(tree.visit);
    return 0;
}