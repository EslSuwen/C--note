#include<iostream>
using namespace std;
void main()
{
	int n,N,i,sum=0;
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
		N=n%i;
		if(N==0)
			sum=sum+i;
	}
	cout<<sum<<endl;
}