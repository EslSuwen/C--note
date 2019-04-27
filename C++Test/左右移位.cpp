#include<iostream.h>
int move(int value,int n);
void main()
{
	int n,value;
	cin>>value>>n;
	cout<<move(value,n)<<endl;
}
int move(int value,int n)
{
	int a,b=1,c,i=0,j;
	a=value;
	while(a!=0)
	{
		a=a/10; 
		i++;
	}		
	while(i!=1)
	{
		b=b*10;
		i--;
	}
	a=value;	
	if(n<0)
	{
		n=-n;
		for(j=1;j<=n;j++)
		{
			
			c=a/b;
			a=a%b;
			a=a*10+c;
		}
		return a;
	}
	else if(n>0)
	{
		for(j=1;j<=n;j++)
		{
			c=a%10;
			a=a/10;
			a=c*b+a;
		}
		return a;
	}
	else
		return a;
}