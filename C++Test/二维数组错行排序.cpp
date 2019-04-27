/*2输入一个m*n的矩阵，
将该矩阵的第一行按从小到大排序，第二行按从大到小排序，第三行从小到大排序，第四行从大到小排序，
以此类推……，输出最后排序完成之后的结果。要求数组输入、输出以及排序做成函数。*/
#include<iostream.h>
#include<iomanip.h>
const int N=100;
const int M=100;
void arrayIn(double *,int n,int m);
void arrayOut(double *,int n,int m);
void arraySort1(double *p,int n);
void arraySort2(double *p,int n);
void arraySort(double *p,int n,int m);
void main()
{
	double array[N][M];
	int n,m;
	cout<<"输入矩阵的行数：(1-100):\n";
	cin>>n;
	cout<<"输入矩阵的列数：(1-100):\n";
	cin>>m;
	cout<<"输入"<<m*n<<"个数据:\n";
	arrayIn(*array,n,m);
	arraySort(*array,n,m);
	arrayOut(*array,n,m);
}
void arrayIn(double *p,int n,int m)
{
	for(int i=0;i<n*m;i++)
		cin>>*p++;	
}
void arrayOut(double *p,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<setw(3)<<*p++;
		cout<<endl;
	}
}
void arraySort1(double *p, int n)
{	
    for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(p[i]>p[j])
			{
				double t;
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
}
void arraySort2(double *p, int n)
{
	
    for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(p[i]<p[j])
			{
				double t;
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
}
void arraySort(double *p,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			arraySort1(p+i*m,m);
		else
			arraySort2(p+i*m,m);
	}
}