//输入n个数据，对这n个数据按选择排序法进行排序输出。
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
	int i,j,k;double t,m;
	for (i=0;i<n-1;i++){ 
		k=i;m=array[i];
		for (j=i+1;j<n;j++)
			if (m<array[j]){ 
				m=array[j];k=j;
			}
			if (i!=k){
				t=array[i];array[i]=array[k];array[k]=t;
			}
	}
}