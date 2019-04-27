#include<iostream.h>
void main()
{
	int a[100],n,i,t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n;k++)
		{
			cout<<a[k]<<" ";
		}
		cout<<endl;
        t=a[0];
		for(int l=0;l<n-1;l++)
		{
			a[l]=a[l+1];
		}
		a[n-1]=t;
	}
}