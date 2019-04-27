/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-03 21:21:20
 * @LastEditTime: 2019-04-04 08:04:44
 */
#ifndef _SPARSE_MATRIX_CPP
#define _SPARSE_MATRIX_CPP
#include "SparseMatrix.h"

template <class T>
SparseMatrix<T>::SparseMatrix(int maxSz)
{
    maxTerms = maxSz;
    if (maxSz < 1)
    {
        exit(1);
    }
    smArray = new Trituple<T>[maxSz];
    if (smArray == NULL)
        exit(1);
    Rows = Cols = Terms = 0;
}

template <class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T> &x)
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
}

template <class T>
SparseMatrix<T> SparseMatrix<T>::Transpos()
{
    SparseMatrix<T> b(maxTerms);
    b.Rows = Cols;
    b.Cols = Rows;
    b.Terms = Terms;
    if (Terms > 0)
    {
        int k, i, CurrentB = 0;
        for (k = 0; k < Cols; k++)
            for (i = 0; i < Terms; i++)
                if (smArray[i].col == k)
                {
                    b.smArray[CurrentB].row = k;
                    b.smArray[CurrentB].col = smArray[i].row;
                    b.smArray[CurrentB].value = smArray[i].value;
                    CurrentB++;
                }
    }
    return b;
}

template <class T>
SparseMatrix<T> SparseMatrix<T>::FastTranspos()
{
    int *rowSize = new int[Cols];
    int *rowStart = new int[Cols];
    SparseMatrix<T> b(maxTerms);
    b.Rows = Cols;
    b.Cols = Rows;
    b.Terms = Terms;
    if (Terms > 0)
    {
        int i, j;
        for (i = 0; i < Cols; i++)
            rowSize[i] = 0;
        for (i = 0; i < Terms; i++)
            rowSize[smArray[i].col]++;
        rowStart[0] = 0;
        for (i = 1; i < Cols; i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        for (int i = 0; i < Terms; i++)
        {
            j = rowStart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        }
    }
    delete[] rowSize;
    delete[] rowStart;
    return b;
}

#endif