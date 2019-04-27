#include<iostream.h>
#include<math.h>
void main()
{
	int n,i;
    cout<<"请输入一个正整数：";
	cin>>n;
	i=2;
	if(i<=n-1)
	{
       while(n%i!=0)
	   {
		   i++;
	   }
	   if(i==n)
		   cout<<""<<n<<"是质数\n";
	   else
		   cout<<""<<n<<"不是质数\n";
	
	}
	else
		cout<<"input error!"<<endl;
}