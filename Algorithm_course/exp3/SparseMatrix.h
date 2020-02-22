/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-03 21:10:56
 * @LastEditTime: 2019-04-04 08:26:26
 */
#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_
#include <cstdlib>
#include <iostream>
using namespace std;

const int DefaultSize1 = 100;
template <class T>
struct Trituple
{
    int row, col;                          //非零元素的 行号，列号
    T value;                               //非零元素的值
    Trituple<T> &operator=(Trituple<T> &x) //结点赋值
    {
        row = x.row;
        col = x.col;
        value = x.value;
        return *this;
    }
};

template <class T>
class SparseMatrix
{

  private:
    int Rows, Cols, Terms;
    Trituple<T> *smArray;
    int maxTerms;

  public:
    SparseMatrix(int maxSz = DefaultSize1);
    SparseMatrix(SparseMatrix<T> &x);
    ~SparseMatrix()
    {
        delete[] smArray;
    }

    SparseMatrix<T> Transpos();                          //转置
    SparseMatrix<T> FastTranspos();                      //快速转置
    SparseMatrix<T> &operator=(const SparseMatrix<T> &x) //重载=
    {
        Rows = x.Rows;
        Cols = x.Cols;
        Terms = x.Terms;
        maxTerms = x.maxTerms;
        smArray = new Trituple<T>[maxTerms];
        if (smArray == NULL)
            exit(1);
        for (int i = 0; i < Terms; i++)
            smArray[i] = x.smArray[i];
        return *this;
    }
    friend ostream &operator<<(ostream &out, SparseMatrix<T> &M)
    {
        out << "rows = " << M.Rows << endl;
        out << "clos = " << M.Cols << endl;
        out << "Nonzero terms = " << M.Terms << endl;
        for (int i = 0; i < M.Terms; i++)
            out << "M[" << M.smArray[i].row << "][" << M.smArray[i].col << "]=" << M.smArray[i].value << endl;
        return out;
    }
    friend istream &operator>>(istream &in, SparseMatrix<T> &M)
    {
        cout << "Enter number of rows, columns, and terms" << endl;
        in >> M.Rows >> M.Cols >> M.Terms;
        if (M.Terms > M.maxTerms)
            exit(1);
        for (int i = 0; i < M.Terms; i++)
        {
            cout << "Enter row,column,and value of term:" << i + 1 << endl;
            in >> M.smArray[i].row >> M.smArray[i].col >> M.smArray[i].value;
        }
        return in;
    }
};
#include "SparseMatrix.cpp"
#endif