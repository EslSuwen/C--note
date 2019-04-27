#include"iostream.h"
#include"math.h"
void main()
{ int i,n,flag;//n表示一个整数
  cout<<"请输入一个数:";
  cin>>n;
  flag=1;
  for(i=2;i<=sqrt(n);i++)
	if(n%i==0)
	{ flag=0;break;}
    if(flag)
	  cout<<n<<"是一个素数.\n";
	else
	  cout<<n<<"不是一个素数.\n";
}