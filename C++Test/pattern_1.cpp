#include<iostream>
using namespace std;
void main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int k=1;k<=i-1;k++)
			cout<<'*';
		cout<<endl;
	}
}