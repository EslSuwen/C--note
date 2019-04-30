/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-27 10:52:13
 * @LastEditTime: 2019-04-30 09:19:59
 */
#include <iostream>
using namespace std;

enum PointerTag
{
    THREAD,
    LINK,
};

template <class T>
struct BinaryTreeNodeThd
{
    T _data;
    BinaryTreeNodeThd<T> *_left;
    BinaryTreeNodeThd<T> *_right;
    PointerTag _leftTag;
    PointerTag _rightTag;

    BinaryTreeNodeThd(const T &data) //������ �����ö�������ָ�����������Ŀ�ָ������Žڵ��ǰ���ͺ����Ϣ
        : _data(data), _left(NULL), _right(NULL), _leftTag(LINK), _rightTag(LINK)
    {
    }
};

template <class T>
class BinaryTreeThd
{
    typedef BinaryTreeNodeThd<T> Node;

  private:
    Node *_root;

  public:
    BinaryTreeThd()
        : _root(NULL)
    {
    }

    BinaryTreeThd(const T *a, size_t size, size_t index, const T &invalid)
    {

        _root = _CreateBinaryTreeThd(a, size, index, invalid);
    }

    //����������
    void InorderThreading()
    {
        Node *prev = NULL;
        _InorderThreading(_root, prev);
    }

    //����������
    void PrevtorderThreading()
    {
        Node *prev = NULL;
        _PrevorderThreading(_root, prev);
    }

    //��������������
    void _InorderThd()
    {
        Node *cur = _root;
        while (cur)
        {
            //	��������ߵ�Ҷ�ӽڵ�
            while (cur->_leftTag == LINK)
            {
                cur = cur->_left;
            }

            cout << cur->_data << " ";

            while (cur->_rightTag == THREAD)
            {
                cur = cur->_right;
                cout << cur->_data << " ";
            }
            //����������
            cur = cur->_right;
        }
    }

    //��������������������
    void _Prevorderthd()
    {
        Node *cur = _root;
        if (cur == NULL)
        {
            return;
        }
        while (cur)
        { //�����ߵĽڵ�
            while (cur->_leftTag == LINK)
            {
                cout << cur->_data << " ";
                cur = cur->_left;
            }
            cout << cur->_data << " ";
            //ת�Ƶ��ұߵĽڵ�
            cur = cur->_right;

            /*while(cur->_rightTag ==THREAD )
			{
			cur=cur->_right ;
			cout<<cur->_data<<" " ;
			}*/
        }
    }

  protected:
    //
    Node *_CreateBinaryTreeThd(const T *a, size_t size, size_t &index, const T &invalid)
    {
        Node *root = NULL;
        if (index < size && a[index] != invalid)
        {
            root = new Node(a[index]);
            root->_left = _CreateBinaryTreeThd(a, size, ++index, invalid);
            root->_right = _CreateBinaryTreeThd(a, size, ++index, invalid);
        }
        return root;
    }

    //��������������
    void _InorderThreading(Node *cur, Node *&prev)
    {
        if (cur == NULL)
        {
            return;
        }
        //�ݹ����������
        _InorderThreading(cur->_left, prev);
        if (cur->_left == NULL)
        {
            cur->_leftTag = THREAD;
            cur->_left = prev;
        }
        if (prev && prev->_right == NULL)
        {
            prev->_rightTag = THREAD;
            prev->_right = cur;
        }
        prev = cur;
        //�ݹ����������
        _InorderThreading(cur->_right, prev);
    }

    //��������������
    void _PrevorderThreading(Node *cur, Node *&prev)
    {
        if (cur == NULL)
            return;
        //��ǰ������
        if (cur->_left == NULL)
        {
            cur->_leftTag = THREAD;
            cur->_left = prev;
        }
        //�ú�������
        if (prev && prev->_right == NULL)
        {
            prev->_rightTag = THREAD;
            prev->_right = cur;
        }

        prev = cur;

        if (cur->_leftTag == LINK)
        {
            _PrevorderThreading(cur->_left, prev);
        }

        if (cur->_rightTag == LINK)
        {
            _PrevorderThreading(cur->_right, prev);
        }
    }
};
