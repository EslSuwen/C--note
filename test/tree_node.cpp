#include <iostream>
using namespace std;

class TreeNode
{
public:
    int date;
    TreeNode *Lchild;
    TreeNode *Rchild;
    TreeNode(int t = 10)
    {
        date = t;
        Lchild = NULL;
        Rchild = NULL;
    }
};
int main()
{
    TreeNode *p = new TreeNode;
    cout << p->date << endl;
    system("pause");
    return 0;
}
