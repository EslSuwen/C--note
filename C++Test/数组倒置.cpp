//����n�����ݴ��������У��������е��������ݵ��ã�����0��Ԫ�ػ������һ��Ԫ�أ���һ��Ԫ�ػ��������ڶ���Ԫ�أ��Դ����ƣ�
//Ȼ����������е�Ԫ�ء�
#include<iostream.h>
#include<iomanip.h>
const int N=100;
void array_in(double array[],int n);
void array_out(double array[],int n);
void daozhi(double array[],int n);
void main()
{
	double x[N];
	int n;
	cout<<"���������������1-100��";
	cin>>n;
	array_in(x,n);
	array_out(x,n);
	cout<<"���ú����"<<endl;
	daozhi(x,n);
	array_out(x,n);
}
void array_in(double array[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"array["<<i<<"]=";
		cin>>array[i];
	}
}
void array_out(double array[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i%5==0)
			cout<<endl;
		cout<<setw(5)<<array[i];
	}
	cout<<endl;
}
void daozhi(double array[],int n)
{
	int i;
	double t;
	for(i=0;i<n/2;i++)
	{
		t=array[i];
		array[i]=array[n-1-i];
		array[n-1-i]=t;
	}
}
void paixu(double array[],int n)
{
	int i,j;
	double t;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(array[i]<array[j])
			{
				t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
}