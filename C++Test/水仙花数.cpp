#include <iostream>
using namespace std; 
void main()
{	
	int n,a,b,c;
	for(n=100;n<1000;n++)
	{
		a=n%10;
		b=(n/10)%10;
		c=n/100;
		if(n==a*a*a+b*b*b+c*c*c)
			cout<<n<<"  "<<endl;
	}
}