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
    cout << "ǰ��ݹ������" << endl;
    tree.PreOrder(tree.visit);
    cout << "\n�ǵݹ������" << endl;
    tree.PreOrderStack(tree.visit);
    cout << "������һ����������'#'���������磺1(2,3)��" << endl;
    cin >> tree1;
    cout << "ǰ��ݹ������" << endl;
    tree1.PreOrder(tree.visit);
    cout << "\n�ǵݹ������" << endl;
    tree1.PreOrderStack(tree.visit);
    return 0;
}