#include<iostream.h>
#include<iomanip.h>
void main()
{
	 int i,j;
	 char ch;
	 ch='*';
	 for(i=1;i<=9;i++)
	 {
		 for(j=1;j<=i;j++)
			 cout<<i<<ch<<j<<"="<<i*j<<setw(2);
			 cout<<endl;
	 }
}

