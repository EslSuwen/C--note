#include<iostream.h>
void main()
{
	int a[100],n;
	a[0]=1;
	cin>>n;
	for(int k=1;k<=n-1;k++)
			cout<<" ";
	cout<<a[0]<<endl;
	a[0]=a[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int k=1;k<=n-i;k++)
			cout<<" ";
		for(int j=0;j<=i-1;j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<endl;
		a[i]=1;
		for(j=i-1;j>=1;j--)
		a[j]=a[j-1]+a[j];
	}
}