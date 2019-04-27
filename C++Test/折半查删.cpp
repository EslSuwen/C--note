//输入n个数据存入数组中，然后输入一个数据，并在数组中按折半查找法查找是否存在该数据，如果存在，删除该数据，输出数组中的元素。
#include<iostream.h>
#include<iomanip.h>
const int N=100;
void array_in(double array[],int n);
void array_out(double array[],int n);
void paixu(double array[],int n);
void chaozhao(double array[],int n,double number);
void main()
{
	double array[N],number;
	int n;
	cout<<"请输入数组个数（1-100）\n";
	cin>>n;
	array_in(array,n);
	paixu(array,n);
	array_out(array,n);
	cout<<"查找数据为：\n";
	cin>>number;
	chaozhao(array,n,number);
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
void chaozhao(double array[],int n,double number)
{
	int low=0,high=n-1,mid,flag=0;
	while(low<=high)
	{ 
		mid=(low+high)/2;
		if(number==array[mid])
		{
			flag=1;break;
		}
		else if(number<array[mid]) 
			high=mid-1;
		else 
			low=low+1;
	}
	if(flag)
	{
		for(int i=mid;i<n-1;i++)
			array[i]=array[i+1];
		n--;
	
		chaozhao(array,n,number);
	}
	else 
	array_out(array,n);
	cout<<endl;
}
