/*1������һ��m*n�ľ�����þ����е����а����λ�á�
ע����ν������ָһ�������е�Ԫ�������ڵ���������������ڵ�������С��Ԫ�ص�λ�ã����±�����±꣩��
Ҫ�������������������������������*/
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
	cout<<"��������������(1-100):\n";
	cin>>n;
	cout<<"��������������(1-100):\n";
	cin>>m;
	cout<<"����"<<m*n<<"������:\n";
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
			cout<<"����Ϊ��a["<<i<<"]["<<a<<"]"<<endl;
	}
}
