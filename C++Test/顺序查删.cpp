//输入n个数据存入数组中，然后输入一个数据，并在数组中按顺序查找法查找是否存在该数据，如果存在，删除该数据，输出数组中元素。
#include<iostream.h>
#include<iomanip.h>
const int N=100;
void array_in(double array[],int n);
void shanchu(double array[],int n,double a);
void array_out(double array[],int n);
void main()
{
	double x[N],a;
	int n;
	cout<<"请输入数组个数（1-100）:\n";
	cin>>n;
	array_in(x,n);
	cout<<"请输入需删除的数:\n";
	cin>>a;
	shanchu(x,n,a);
}
void array_in(double array[],int n)
{
	for(int i=0;i<n;i++)
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
void shanchu(double array[],int n,double a)
{
	int i,j,flag=1;
	for(i=0;i<n;i++)
	{
		if(array[i]==a)
		{
			for(j=i;j<n-1;j++)
			{
				array[j]=array[j+1];		
			}
			i--;
			n--;
			flag=0;
		}		
	}
	array_out(array,n);
	if(flag==1)
		cout<<"\n未找到 "<<a<<"。";
	else
		cout<<"\n已删除 "<<a<<"。";
	cout<<endl;
}
/*{
while(find(data,n,x)!=-1)
int j=find(data,n,x);
for(int i=j;i<n-1;i++)
data[i]=data[i+1];
n--;
}*/
