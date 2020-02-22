#include<iostream.h>
int numberOfInt(int n);
void main()
{
	int n;
	cin>>n;
	cout<<numberOfInt(n)<<endl;
}
int numberOfInt(int n)
{
	int i=0;
	while(n!=0)
	{
		n/=10;
		i++;
	}
	return i;
}