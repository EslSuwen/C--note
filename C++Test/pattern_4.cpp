#include<iostream>
using namespace std;
void main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
        for (int j=1;j<=n-i;j++)
			cout<<" ";
		if(i==1||i==n)
			for(int k=1;k<=2*i-1;k++)
				cout<<'*';
			else{
				cout<<'*';
				for (int l=1;l<=2*(i-1)-1;l++) 
				cout<<" ";
				cout<<'*';
			}
	    cout<<endl;
	}
}