#include<iostream.h>
int isRev(int n);
void main()
{
	int n;
	cin>>n;
	if(isRev(n))
		cout<<"yes\n";
	else
		cout<<"n\n";
}
int isRev(int n)
{
	int a,s=0,N=n;
	while(n!=0)
	{
		
		a=n%10;
        s=s*10+a;
		n=n/10;		
	}
	if(s==N)
		return 1;
	else		
		return 0;
}