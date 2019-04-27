#include<iostream>
using namespace std;
void main()
{
	int n,i,sum=0;
	cin>>n;
	while(n>0)
	{
		i=n%10;
		sum+=i;
		n/=10;
	}
	cout<<sum<<endl;
}
