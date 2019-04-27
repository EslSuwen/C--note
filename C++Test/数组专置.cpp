/*输入一个n*n的方阵，在不用其它二维数组的情况下，将该方阵转置后输出。（要求数组的输入、输出以及转置做成函数）*/
#include<iostream.h>
#include<iomanip.h>
const int N=100;
const int M=100;
void arrayIn(double *,int n,int m);
void arrayOut(double *,int n,int m);
void arrayZhuanzhi(double *p,int n,int m);
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
	arrayZhuanzhi(*array,n,m);
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
void arrayZhuanzhi(double *p,int n,int m)
{
	double q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			q=*(p+m*i+j);
			*(p+m*i+j)=*(p+m*j+i);
			*(p+m*j+i)=q;			
		}		
	}
}