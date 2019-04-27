#include<iostream.h>
#include<math.h>
int sushu(int);
void main()
{
	int x,b,m;
	b=0;
	for(x=100;x<=200;x++)
	{
		sushu(x);	
		if(sushu(x)==0)
		{
			b++;
			cout<<x<<" ";
			m++;
			if(m%10==0)
				cout<<endl;
		}
	}
	cout<<"素数的个数是"<<b<<endl;
}
int sushu(int x)
{
	int a,n;
	for(n=2;n<x;n++)
	{
		if(x%n!=0)
			a=0;
		else
		{
			a=1;
			break;
		}
		
	}

	return a;

	
}


