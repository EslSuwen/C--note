//输入n个数据，对这n个数据按冒泡排序法进行排序输出。
#include<iostream.h>
#include<iomanip.h>
const int N=100;
void array_in(double array[],int n);
void array_out(double array[],int n);
void paixu(double array[],int n);
void main()
{
	double x[N];
	int n;
	cout<<"请输入数组个数（1-100）\n";
	cin>>n;
	array_in(x,n);
	array_out(x,n);
	cout<<"排序后输出"<<endl;
	paixu(x,n);
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
void paixu(double array[],int n)
{
	int i,j;
	double t;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(array[j]<array[j+1])
			{
				t=array[j];
				array[j]=array[j+1];
				array[j+1]=t;
			}
}