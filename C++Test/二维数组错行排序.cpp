/*2����һ��m*n�ľ���
���þ���ĵ�һ�а���С�������򣬵ڶ��а��Ӵ�С���򣬵����д�С�������򣬵����дӴ�С����
�Դ����ơ������������������֮��Ľ����Ҫ���������롢����Լ��������ɺ�����*/
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
	cout<<"��������������(1-100):\n";
	cin>>n;
	cout<<"��������������(1-100):\n";
	cin>>m;
	cout<<"����"<<m*n<<"������:\n";
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