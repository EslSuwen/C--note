/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-03-20 18:50:26
 * @LastEditTime: 2019-03-20 19:49:02
 */
#include <iostream>
const int defaultSize = 100;
using namespace std;
template <class T>
class SeqList
{
  protected:
	T *data;				  //�������
	int maxSize;			  //�������ɱ��������
	int last;				  //��ǰ�Ѵ��������λ�ã���0��ʼ��
	void reSize(int newSize); //�ı�data����ռ��С
  public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T> &L);
	~SeqList()
	{ //��������
		delete[] data;
	}
	int Size()
	{ //������������ɱ������
		return maxSize;
	}
	int Length()
	{ //�������
		return last + 1;
	}
	int Search(T &x);
	int Locate(int i);
	bool getData(int i, T &x)
	{ //ȡ�����е�i�������ֵ
		if (i > 0 && i <= last + 1)
		{
			x = data[i - 1];
			return true;
		}
		else
		{
			return false;
		}
	}
	void setData(int i, T &x)
	{ //��x�޸ı��е�i������֮��
		if (i > 0 && i <= last + 1)
		{
			data[i - 1] = x;
		}
	}
	bool Insert(int i, T &x);
	bool Remove(int i, T &x);
	bool IsEmpty()
	{ //�жϱ��Ƿ�Ϊ�գ����򷵻�true���ǿշ���false
		return (last == -1) ? true : false;
	}
	bool IsFull()
	{ //�жϱ��Ƿ��������򷵻�true�����򷵻�false
		return (last == maxSize - 1) ? true : false;
	}
	void input();
	void output();
	SeqList<T> operator=(SeqList<T> &L);
};
/**
 * ���캯��
 * ͨ��ָ������sz��������ĳ���
 */
template <class T>
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		maxSize = sz;
		last = -1;			   //�ñ��ʵ�ʳ���Ϊ��
		data = new T[maxSize]; //����˳���洢����
		if (data == NULL)
		{ //��̬����ʧ��
			cerr << "�洢�������" << endl;
			exit(1);
		}
	}
}
/**
 * ���ƹ��캯��
 * �ò������и���������˳����ʼ���½���˳���
 */
template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize]; //����˳���洢����
	if (data == NULL)
	{ //��̬����ʧ��
		cerr << "�洢�������" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value);
		data[i - 1] = value;
	}
}
/**
 * �ı�data����ռ��С
 * ˽�к���������˳���Ĵ洢����ռ��С���������Ԫ�ظ���ΪnewSize
 */
template <class T>
void SeqList<T>::reSize(int newSize)
{
	if (newSize <= 0) //�������ĺ�����
	{
		cerr << "��Ч�������С" << endl;
		return;
	}
	if (newSize != maxSize)
	{ //�޸�
		T *newarray = new T[newSize];
		if (newarray == NULL)
		{
			cerr << "�洢�������" << endl;
			exit(1);
		}
		int n = last + 1;
		T *srcptr = data;	  //Դ�����׵�ַ
		T *destptr = newarray; //Ŀ�������׵�ַ
		while (n--)
		{
			*destptr++ = *srcptr++; //����
		}
		delete[] data; //ɾ��������
		data = newarray;
		maxSize = newSize; //����������
	}
}
/**
 * ��������������x�ڱ���λ�ã����ر������
 * �ڱ���˳�����������ֵxƥ��ı���ҵ��������ظñ����ǵڼ���Ԫ�أ�����������0����ʾ����ʧ��
 */
template <class T>
int SeqList<T>::Search(T &x)
{
	for (int i = 0; i <= last; i++)
		if (data[i] == x)
			return i + 1;
	return 0;
}
/**
 * ��λ��������λ��i������������ر������
 * �������ص�i�����������鷶Χ���������λ�ã�����������0����ʾ��λʧ�ܡ�
 */
template <class T>
int SeqList<T>::Locate(int i)
{
	if (i >= 1 && i <= last + 1)
		return i - 1;
	else
		return 0;
}
/**
 * ���뺯��������x�ڵ�i������֮��
 * ����Ԫ��x���뵽���е�i�������������鷶Χ������֮�󡣺������ز���ɹ�����Ϣ��������ɹ��򷵻�true,���򷵻�false.
 */
template <class T>
bool SeqList<T>::Insert(int i, T &x)
{
	if (last == maxSize - 1) //�������ܲ������
	{
		return false;
	}
	if (i < 0 || i > last + 1) //����i���������ܲ���
		return false;
	for (int j = last; j >= i; j--)
	{
		data[j + 1] = data[j]; //���κ��ƣ�Ϊx�ڳ�λ��
	}
	data[i] = x; //����
	last++;		 //�������λ�ü�1
	return true; //�ɹ�����
}
/**
 * ɾ��������ɾ����i�����ͨ��x���ر����ֵ
 * �ӱ���ɾ����i�����������鷶Χ�������ͨ�������Ͳ���x����ɾ����Ԫ��ֵ��
 * ��������ɾ���ɹ�����Ϣ����ɾ���ɹ��򷵻�true�����򷵻�false��
 */
template <class T>
bool SeqList<T>::Remove(int i, T &x)
{
	if (last == -1) //��ղ���ɾ��
		return false;
	if (i < 1 || i > last + 1) //����i������
		return false;
	x = data[i - 1]; //���ڱ�ɾ��Ԫ��
	for (int j = i; j <= last; j++)
	{
		data[j - 1] = data[j]; //������ǰ�ƶ�
	}
	last--;		 //�������λ�ü�1
	return true; //�ɹ�ɾ��
}
/**
 * ���뺯����
 */
template <class T>
void SeqList<T>::input()
{
	cout << "��ʼ����˳������������Ԫ�ظ�����";
	int length; //����Ҫ˳���Ԫ�ظ���
	cin >> length;
	if (length > maxSize)
	{
		cout << "��Ԫ�ظ����������󣬷�Χ���ܳ���" << maxSize << "��";
		return;
	}
	last = length - 1; //�������λ��
	for (int i = 0; i <= last; i++)
	{
		cin >> data[i];
	}
}
/**
 * ���������
 */
template <class T>
void SeqList<T>::output()
{
	for (int i = 0; i <= last; i++)
	{
		cout << "#" << i + 1 << ":" << data[i] << endl;
	}
}
/**
 *�����帳ֵ�����������ز�����˳������帳ֵ
 */
template <class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L)
{
	int size;
	T value;
	size = L.Size();
	if (maxSize != size)
	{
		reSize(size);
	}
	last = L.Length() - 1;
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value);
		data[i - 1] = value;
	}
}