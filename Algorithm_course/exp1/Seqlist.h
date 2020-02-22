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
	T *data;				  //存放数组
	int maxSize;			  //最大可容纳表项的项数
	int last;				  //当前已存表项的最后位置（从0开始）
	void reSize(int newSize); //改变data数组空间大小
  public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T> &L);
	~SeqList()
	{ //析构函数
		delete[] data;
	}
	int Size()
	{ //计算表最大可容纳表项个数
		return maxSize;
	}
	int Length()
	{ //计算表长度
		return last + 1;
	}
	int Search(T &x);
	int Locate(int i);
	bool getData(int i, T &x)
	{ //取出表中第i个表项得值
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
	{ //用x修改表中第i个表项之后
		if (i > 0 && i <= last + 1)
		{
			data[i - 1] = x;
		}
	}
	bool Insert(int i, T &x);
	bool Remove(int i, T &x);
	bool IsEmpty()
	{ //判断表是否为空，空则返回true，非空返回false
		return (last == -1) ? true : false;
	}
	bool IsFull()
	{ //判断表是否满，满则返回true，否则返回false
		return (last == maxSize - 1) ? true : false;
	}
	void input();
	void output();
	SeqList<T> operator=(SeqList<T> &L);
};
/**
 * 构造函数
 * 通过指定参数sz定义数组的长度
 */
template <class T>
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		maxSize = sz;
		last = -1;			   //置表的实际长度为空
		data = new T[maxSize]; //创建顺序表存储数组
		if (data == NULL)
		{ //动态分配失败
			cerr << "存储分配错误！" << endl;
			exit(1);
		}
	}
}
/**
 * 复制构造函数
 * 用参数表中给出的已有顺序表初始化新建的顺序表
 */
template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize]; //创建顺序表存储数组
	if (data == NULL)
	{ //动态分配失败
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value);
		data[i - 1] = value;
	}
}
/**
 * 改变data数组空间大小
 * 私有函数：扩充顺序表的存储数组空间大小，新数组的元素个数为newSize
 */
template <class T>
void SeqList<T>::reSize(int newSize)
{
	if (newSize <= 0) //检查参数的合理性
	{
		cerr << "无效的数组大小" << endl;
		return;
	}
	if (newSize != maxSize)
	{ //修改
		T *newarray = new T[newSize];
		if (newarray == NULL)
		{
			cerr << "存储分配错误！" << endl;
			exit(1);
		}
		int n = last + 1;
		T *srcptr = data;	  //源数组首地址
		T *destptr = newarray; //目的数组首地址
		while (n--)
		{
			*destptr++ = *srcptr++; //复制
		}
		delete[] data; //删除老数组
		data = newarray;
		maxSize = newSize; //复制新数组
	}
}
/**
 * 搜索函数：搜索x在表中位置，返回表项序号
 * 在表中顺序搜索与给定值x匹配的表项，找到则函数返回该表项是第几个元素，否则函数返回0，表示搜索失败
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
 * 定位函数：定位第i个表项，函数返回表项序号
 * 函数返回第i（不超过数组范围）个表项的位置，否则函数返回0，表示定位失败。
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
 * 插入函数：插入x在第i个表项之后
 * 将新元素x插入到表中第i个（不超过数组范围）表项之后。函数返回插入成功的信息，若插入成功则返回true,否则返回false.
 */
template <class T>
bool SeqList<T>::Insert(int i, T &x)
{
	if (last == maxSize - 1) //表满不能插入操作
	{
		return false;
	}
	if (i < 0 || i > last + 1) //参数i不合理，不能插入
		return false;
	for (int j = last; j >= i; j--)
	{
		data[j + 1] = data[j]; //依次后移，为x腾出位置
	}
	data[i] = x; //插入
	last++;		 //表中最后位置加1
	return true; //成功插入
}
/**
 * 删除函数：删除第i个表项，通过x返回表项的值
 * 从表中删除第i（不超过数组范围）个表项，通过引用型参数x返回删除的元素值。
 * 函数返回删除成功的信息，若删除成功则返回true，否则返回false。
 */
template <class T>
bool SeqList<T>::Remove(int i, T &x)
{
	if (last == -1) //表空不能删除
		return false;
	if (i < 1 || i > last + 1) //参数i不合理
		return false;
	x = data[i - 1]; //存在被删除元素
	for (int j = i; j <= last; j++)
	{
		data[j - 1] = data[j]; //依次往前移动
	}
	last--;		 //表中最后位置减1
	return true; //成功删除
}
/**
 * 输入函数：
 */
template <class T>
void SeqList<T>::input()
{
	cout << "开始建立顺序表，请输入表中元素个数：";
	int length; //所需要顺序表元素个数
	cin >> length;
	if (length > maxSize)
	{
		cout << "表元素个数输入有误，范围不能超过" << maxSize << "：";
		return;
	}
	last = length - 1; //数组最后位置
	for (int i = 0; i <= last; i++)
	{
		cin >> data[i];
	}
}
/**
 * 输出函数：
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
 *表整体赋值函数：用重载操作将顺序表整体赋值
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