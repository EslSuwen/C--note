/*1、输入一个m*n的矩阵，求该矩阵中的所有鞍点的位置。
注：所谓鞍点是指一个矩阵中的元素在所在的行上最大，在其所在的列上最小的元素的位置（行下标和列下标），
要求：输入和输出和输出鞍点做成三个函数*/
#include<iostream.h>
#include<iomanip.h>
const int N=100;
const int M=100;
void arrayIn(double *,int n,int m);
void arrayOut(double *,int n,int m);
void arrayAn(double *p,int n,int m);
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
	arrayOut(*array,n,m);
	arrayAn(*array,n,m);
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
void arrayAn(double *p,int n,int m)
{
	double i,k,j,a=0,max,flag;
	for(i=0;i<n;i++)
	{	
		flag=1;
		max=*(p+i*m);
		for(j=0;j<m;j++)
		{
			if(max<*(p+j+i*m))
			{
				max=*(p+j+i*m);
				a=j;
			}
		}
		for(k=0;k<n;k++)
		{
			if(max>*(p+a+m*k))
				flag=0;
		}
		if(flag==1)
			cout<<"鞍点为：a["<<i<<"]["<<a<<"]"<<endl;
	}
}
