//输入n个整数，在不改变顺序的情况下将重复的数据删除只剩一个，然后输入删除重复数据后的数据。
#include<iostream.h>
#include<iomanip.h>
void array_in(double array[],int n);
void array_out(double array[],int n);
void shanchong(double array[],int n);
void main()
{
	int n;
	double *array;
	cout<<"请输入数组个数（1-100）:\n";
	cin>>n;
	array=new double[n];
	array_in(array,n);
	shanchong(array,n);
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
	for(int i=0;i<n;i++)
	{
		if(i%5==0)
			cout<<endl;
		cout<<setw(5)<<array[i];
	}
	cout<<endl;
}
void shanchong(double array[],int n)
{

	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(array[i]==array[j])
			{
				for(k=j;k<n;k++)
					array[k]=array[k+1];

				n--;
				j--;
			}
		}
	}
	array_out(array,n);
}