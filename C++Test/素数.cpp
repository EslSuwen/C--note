#include"iostream.h"
#include"math.h"
void main()
{ int i,n,flag;//n��ʾһ������
  cout<<"������һ����:";
  cin>>n;
  flag=1;
  for(i=2;i<=sqrt(n);i++)
	if(n%i==0)
	{ flag=0;break;}
    if(flag)
	  cout<<n<<"��һ������.\n";
	else
	  cout<<n<<"����һ������.\n";
}