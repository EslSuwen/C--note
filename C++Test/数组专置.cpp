/*����һ��n*n�ķ����ڲ���������ά���������£����÷���ת�ú��������Ҫ����������롢����Լ�ת�����ɺ�����*/
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
	cout<<"��������������(1-100):\n";
	cin>>n;
	cout<<"��������������(1-100):\n";
	cin>>m;
	cout<<"����"<<m*n<<"������:\n";
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