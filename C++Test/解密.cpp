#include<iostream.h>
int decrypt(int n);
void main()
{
	int n;
	cin>>n;
	cout<<decrypt(n)<<endl;
}
int decrypt(int n)
{
	int x1,x2,x3,x4;
	x1=(n/1000+5)%10;
	x2=(n/100%10+5)%10;
	x3=(n/10%10+5)%10;
	x4=(n%10+5)%10;
	return x4*1000+x3*100+x2*10+x1;
}
