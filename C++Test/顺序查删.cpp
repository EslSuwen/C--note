//����n�����ݴ��������У�Ȼ������һ�����ݣ����������а�˳����ҷ������Ƿ���ڸ����ݣ�������ڣ�ɾ�������ݣ����������Ԫ�ء�
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
	cout<<"���������������1-100��:\n";
	cin>>n;
	array_in(x,n);
	cout<<"��������ɾ������:\n";
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
		cout<<"\nδ�ҵ� "<<a<<"��";
	else
		cout<<"\n��ɾ�� "<<a<<"��";
	cout<<endl;
}
/*{
while(find(data,n,x)!=-1)
int j=find(data,n,x);
for(int i=j;i<n-1;i++)
data[i]=data[i+1];
n--;
}*/
